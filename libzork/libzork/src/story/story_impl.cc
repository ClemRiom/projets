#include "story/story_impl.hh"

#include <libzork/story/story.hh>
#include "exceptions.hh"
#include <yaml-cpp/yaml.h>
#include <iostream>

namespace libzork::story
{
    std::unique_ptr<Story> make_story(const fs::path& path) {
        YAML::Node config = YAML::LoadFile(path.string());

        std::string title = config["title"] ? config["title"].as<std::string>() : "Untitled";

        fs::path scripts_path = config["scripts-path"].as<std::string>();
        if (scripts_path.is_relative()) {
            scripts_path = path.parent_path() / scripts_path;
        }

        std::map<std::string, std::unique_ptr<Node>> nodes;
        const Node* start_node = nullptr;

        for (const auto& yaml_node : config["story"]) {
            std::string name = yaml_node["name"].as<std::string>();
            fs::path script_file = scripts_path / yaml_node["script"].as<std::string>();
            
            nodes[name] = make_node(name, script_file);
            if (!start_node) start_node = nodes[name].get();
        }

        for (const auto& yaml_node : config["story"]) {
            std::string name = yaml_node["name"].as<std::string>();
            Node* current = nodes[name].get();

            if (yaml_node["choices"]) {
                for (const auto& choice : yaml_node["choices"]) {
                    std::string text = choice["text"].as<std::string>();
                    std::string target_name = choice["target"].as<std::string>();
                    
                    Node* target = nodes[target_name].get();
                    current->add_choice(target, text);
                }
            }
        }

        auto store = store::make_store();
        store->set_active_node(start_node);

        return std::make_unique<StoryImpl>(title, std::move(nodes), start_node, std::move(store));
    }

    const std::string& StoryImpl::get_title() const
    {
        return title_;
    }

    const Node* StoryImpl::get_current() const
    {
        return current_;
    }

    void StoryImpl::set_current(const Node* node)
    {
        current_ = node;
    }

    const store::Store* StoryImpl::get_store() const
    {
        return store_.get();
    }

    std::ostream& StoryImpl::display(std::ostream& os) const
    {
        os << "digraph story {\n";
        
        for (const auto& [name, node_ptr] : nodes_) {
            const Node* current = node_ptr.get();
            size_t nb_choices = current->list_choices(false).size();
            
            if (nb_choices == 1) {
                os << "    \"" << current->get_name() << "\" -> \"" 
                << current->get_choice(0, false)->get_name() << "\";\n";
            } 
            else if (nb_choices > 1) {
                os << "    \"" << current->get_name() << "\" -> {";
                for (size_t i = 0; i < nb_choices; ++i) {
                    if (i > 0) os << " ";
                    os << "\"" << current->get_choice(i, false)->get_name() << "\"";
                }
                os << "};\n";
            }
        }
        
        os << "}\n";
        return os;
    }

    store::Store* StoryImpl::get_mut_store() {
        return store_.get();
    }

    StoryImpl::StoryImpl(std::string title, std::map<std::string, std::unique_ptr<Node>> nodes, 
              const Node* start_node, std::unique_ptr<store::Store> store)
        : title_{std::move(title)}, nodes_{std::move(nodes)},
          store_{std::move(store)}, current_{start_node} {}

    
    const StoryImpl& to_impl(const Story& story) {
        return static_cast<const StoryImpl&>(story);
    }
    StoryImpl& to_impl(Story& story) {
        return static_cast<StoryImpl&>(story);
    }
} // namespace libzork::story
