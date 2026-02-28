#include "story/story_impl.hh"

#include "exceptions.hh"

namespace libzork::story
{

    const std::string& StoryImpl::get_title() const
    {
        throw NotImplemented();
    }

    const Node* StoryImpl::get_current() const
    {
        throw NotImplemented();
    }

    void StoryImpl::set_current(const Node* node)
    {
        (void)node;
        throw NotImplemented();
    }

    const store::Store* StoryImpl::get_store() const
    {
        throw NotImplemented();
    }

    std::ostream& StoryImpl::display(std::ostream& os) const
    {
        (void)os;
        throw NotImplemented();
    }

} // namespace libzork::story
