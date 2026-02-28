#include <libzork/exceptions.hh>
#include <libzork/runner/interactive.hh>

#include "exceptions.hh"

namespace libzork::runner
{

    InteractiveRunner::InteractiveRunner(std::unique_ptr<story::Story> story,
                                         std::istream& is, std::ostream& os)
        : Runner(std::move(story))
        , is_(is)
        , os_(os)
    {}

    void InteractiveRunner::print_script() const
    {
        const auto* current_node = story_->get_current();
        if (current_node) {
            os_ << current_node->get_text() << "\n";
        }
    }

    void InteractiveRunner::run()
    {
        while (story_->get_current() && !story_->get_current()->list_choices().empty()) {
            print_script();
            bool valid_input = false;
            while (!valid_input) {
                os_ << "> ";
                try {
                    process_input();
                    valid_input = true;
                }
                catch (const RunnerInterrupt& e) {
                    os_ << e.what() << "\n";
                }
            }
        }
        print_script();
    }

} // namespace libzork::runner
