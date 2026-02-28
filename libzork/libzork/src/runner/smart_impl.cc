#include "runner/smart_impl.hh"
#include <libzork/exceptions.hh>
#include "story/story_impl.hh"
#include <yaml-cpp/yaml.h>
#include <sstream>
#include <algorithm>
#include <cctype>

namespace libzork::runner
{
    SmartRunnerImpl::SmartRunnerImpl(std::unique_ptr<story::Story> story,
                                     const fs::path& synonyms_path,
                                     std::istream& is,
                                     std::ostream& os)
        : SmartRunner(std::move(story), is, os)
    {
        try {
            YAML::Node config = YAML::LoadFile(synonyms_path.string());
            for (const auto& entry : config) {
                std::string word = entry["word"].as<std::string>();
                known_words_.insert(word);
                
                if (entry["synonyms"]) {
                    for (const auto& syn : entry["synonyms"]) {
                        std::string synonym = syn.as<std::string>();
                        synonyms_db_[word].insert(synonym);
                        known_words_.insert(synonym); // Ajout au dictionnaire global
                    }
                }
            }
        } catch (...) {
        }
    }

    void SmartRunnerImpl::process_input()
    {
        std::string input;
        if (!std::getline(is_, input)) {
            throw RunnerQuit();
        }

        auto user_tokens = tokenize(input);

        if (user_tokens.empty()) {
            throw RunnerInterrupt("I beg your pardon?");
        }

        const auto* current_node = story_->get_current();
        if (!current_node) return;

        auto choices = current_node->list_choices();
        
        for (size_t i = 0; i < choices.size(); ++i) {
            auto choice_tokens = tokenize(choices[i]);

            if (!has_unmatched_token(user_tokens, choice_tokens)) {
                const auto* next_node = current_node->get_choice(i);
                story_->set_current(next_node);
                story::to_impl(*story_).get_mut_store()->set_active_node(next_node);
                return;
            }
        }

        throw RunnerInterrupt("I beg your pardon?");
    }

    std::unordered_set<std::string>
    SmartRunnerImpl::tokenize(const std::string& str) const
    {
        std::string cleaned = str;
        
        std::transform(cleaned.begin(), cleaned.end(), cleaned.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        for (auto& c : cleaned) {
            if (!std::isalnum(static_cast<unsigned char>(c))) {
                c = ' ';
            }
        }

        std::unordered_set<std::string> tokens;
        std::stringstream ss(cleaned);
        std::string word;
        
        while (ss >> word) {
            if (known_words_.contains(word)) {
                tokens.insert(word);
            }
        }
        return tokens;
    }

    bool SmartRunnerImpl::has_unmatched_token(
        const std::unordered_set<std::string>& user_tokens,
        const std::unordered_set<std::string>& choice_tokens) const
    {
        for (const auto& c_token : choice_tokens) {
            bool matched = false;
            
            if (user_tokens.contains(c_token)) {
                matched = true;
            } 
            else if (synonyms_db_.contains(c_token)) {
                for (const auto& syn : synonyms_db_.at(c_token)) {
                    if (user_tokens.contains(syn)) {
                        matched = true;
                        break;
                    }
                }
            }
            
            if (!matched) {
                return true;
            }
        }
        return false;
    }

} // namespace libzork::runner
