#include "story/node_impl.hh"

#include <fstream>

#include "exceptions.hh"

namespace libzork::story
{
    std::unique_ptr<Node> make_node(const std::string& name,
                                    const fs::path& script_path)
    {
        std::ifstream file(script_path);
        std::stringstream buffer;
        if (file) {
            buffer << file.rdbuf();
        }
        return std::make_unique<NodeImpl>(name, buffer.str());
    }

    const std::string& NodeImpl::get_name() const
    {
        return name_;
    }

    const std::string& NodeImpl::get_text() const
    {
        return text_;
    }

    const Node* NodeImpl::get_choice(size_t index, bool check_conditions) const
    {
        (void)check_conditions;
        if (index >= choices_.size()) {
            return nullptr;
        }
        return choices_[index].target_;
    }

    std::vector<std::string> NodeImpl::list_choices(bool check_conditions) const
    {
        (void)check_conditions;
        std::vector<std::string> res;
        for (const Choice& choice: choices_) {
            res.push_back(choice.text_);
        }
        return res;
    }

    void NodeImpl::add_choice(
        const Node* other, const std::string& text,
        std::vector<std::unique_ptr<vars::Condition>> conditions,
        std::vector<std::unique_ptr<vars::Action>> actions)
    {
        choices_.emplace_back(other, text, std::move(conditions), std::move(actions));
    }

    NodeImpl::NodeImpl(std::string name, std::string text) 
        : name_(std::move(name)), text_(std::move(text)) {}

    const NodeImpl& to_impl(const Node& node)
    {
        return static_cast<const NodeImpl&>(node);
    }

    NodeImpl& to_impl(Node& node)
    {
        return static_cast<NodeImpl&>(node);
    }

} // namespace libzork::story
