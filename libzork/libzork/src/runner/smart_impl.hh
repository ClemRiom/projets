#ifndef SMART_IMPL_HH
#define SMART_IMPL_HH

#include <libzork/runner/smart.hh>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <filesystem>

namespace libzork::runner
{

    class SmartRunnerImpl : public SmartRunner
    {
    public:
        void process_input() override;
        virtual std::unordered_set<std::string>
        tokenize(const std::string& str) const override;
        virtual bool
        has_unmatched_token(const std::unordered_set<std::string>& user_tokens,
                            const std::unordered_set<std::string>&
                                choice_tokens) const override;

        SmartRunnerImpl(std::unique_ptr<story::Story> story,
                        const fs::path& synonyms_path,
                        std::istream& is,
                        std::ostream& os);

        ~SmartRunnerImpl() override = default;
    private:
        std::unordered_map<std::string, std::unordered_set<std::string>> synonyms_db_;
        std::unordered_set<std::string> known_words_;
    };

} // namespace libzork::runner
#endif // !SMART_IMPL_HH
