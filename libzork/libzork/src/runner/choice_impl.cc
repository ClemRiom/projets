#include "runner/choice_impl.hh"

#include <libzork/exceptions.hh>
#include <sstream>

#include "exceptions.hh"
#include "story/story_impl.hh"

namespace libzork::runner
{

    void ChoiceRunnerImpl::print_script() const
    {
        InteractiveRunner::print_script();
        const auto* curent_node = story_->get_current();
        if (!curent_node) {
            return;
        }

        auto choices = curent_node->list_choices();
        if (choices.empty()) {
            return;
        }

        os_ << "\n";
        for (size_t i = 0; i < choices.size(); i++) {
            os_ << (i + 1) << ". " << choices[i] << "\n";
        }
        os_ << "\n";
    }

    void ChoiceRunnerImpl::process_input()
    {
        std::string input;

        if (!std::getline(is_, input)) {
            throw RunnerQuit();
        }

        const auto* current_node = story_->get_current();
        if (!current_node)
        {
            return;
        }

        auto choices = current_node->list_choices();
        size_t num_choices = choices.size();

        try {
            size_t choice_idx = std::stoull(input);

            if (choice_idx < 1 || choice_idx > num_choices) {
                throw std::out_of_range("");
            }

            const auto* next_node = current_node->get_choice(choice_idx - 1);
            story_->set_current(next_node);
            story::to_impl(*story_).get_mut_store()->set_active_node(next_node);
        }
        catch (const std::exception&) {
            throw RunnerInterrupt("Please input an integer between 1 and " + std::to_string(num_choices));
        }
    }

} // namespace libzork::runner
