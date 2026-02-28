#include "story/node_impl.hh"

#include <fstream>

#include "exceptions.hh"

namespace libzork::story
{
    const std::string& NodeImpl::get_name() const
    {
        throw NotImplemented();
    }

    const std::string& NodeImpl::get_text() const
    {
        throw NotImplemented();
    }

    const Node* NodeImpl::get_choice(size_t index, bool check_conditions) const
    {
        (void)check_conditions;
        (void)index;
        throw NotImplemented();
    }

    std::vector<std::string> NodeImpl::list_choices(bool check_conditions) const
    {
        (void)check_conditions;
        throw NotImplemented();
    }

    void NodeImpl::add_choice(
        const Node* other, const std::string& text,
        std::vector<std::unique_ptr<vars::Condition>> conditions,
        std::vector<std::unique_ptr<vars::Action>> actions)
    {
        (void)other;
        (void)text;
        (void)conditions;
        (void)actions;
        throw NotImplemented();
    }

    const NodeImpl& to_impl(const Node& node)
    {
        (void)node;
        throw NotImplemented();
    }

    NodeImpl& to_impl(Node& node)
    {
        (void)node;
        throw NotImplemented();
    }

} // namespace libzork::story
