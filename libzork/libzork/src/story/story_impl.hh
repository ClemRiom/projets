#ifndef STORY_IMPL_HH
#define STORY_IMPL_HH

#include <libzork/story/story.hh>

namespace libzork::story
{

    class StoryImpl : public Story
    {
    public:
        ~StoryImpl() override = default;

        const std::string& get_title() const override;
        const Node* get_current() const override;
        void set_current(const Node* node) override;
        const store::Store* get_store() const override;
        std::ostream& display(std::ostream& os) const override;

        StoryImpl(std::string title, std::map<std::string, std::unique_ptr<Node>> nodes, 
              const Node* start_node, std::unique_ptr<store::Store> store);
        store::Store* get_mut_store();

    private:
        std::string title_;
        std::map<std::string, std::unique_ptr<Node>> nodes_;
        std::unique_ptr<store::Store> store_;
        const Node* current_ = nullptr;
    };

    const StoryImpl& to_impl(const Story& story);
    StoryImpl& to_impl(Story& story);

} // namespace libzork::story
#endif // !STORY_IMPL_HH
