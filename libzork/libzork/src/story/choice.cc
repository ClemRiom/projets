#include "story/choice.hh"

namespace libzork::story {
            Choice::Choice(const Node* target, std::string text,
               std::vector<std::unique_ptr<vars::Condition>> conditions = {},
               std::vector<std::unique_ptr<vars::Action>> actions = {})
            : target_{target}, text_{std::move(text)},
              conditions_{std::move(conditions)}, actions_{std::move(actions)} {}
} // namespace libzork::story
