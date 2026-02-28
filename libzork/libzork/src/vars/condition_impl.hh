#ifndef CONDITION_IMPL_HH
#define CONDITION_IMPL_HH

#include <libzork/vars/condition.hh>

namespace libzork::vars
{

    class ConditionImpl : public Condition
    {
    public:
        ~ConditionImpl() override = default;

        bool apply() const override;

        ConditionImpl(const store::Store& store, std::string variable,
                      std::string comparison, int value);

        private:
            const store::Store& store_;
            std::string variable_;
            std::string comparison_;
            int value_;
    };

} // namespace libzork::vars
#endif // !CONDITION_IMPL_HH
