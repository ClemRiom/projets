#ifndef CHOICE_HH
#define CHOICE_HH

#include "story/node_impl.hh"

namespace libzork::story
{
    class Node;

    class Choice {
    public:
        Choice(const Node* target, std::string text,
               std::vector<std::unique_ptr<vars::Condition>> conditions = {},
               std::vector<std::unique_ptr<vars::Action>> actions = {});

        const Node* target_;
        std::string text_;
        std::vector<std::unique_ptr<vars::Condition>> conditions_;
        std::vector<std::unique_ptr<vars::Action>> actions_;
    };

} // namespace libzork::story
#endif // !CHOICE_HH
