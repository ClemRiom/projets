#ifndef ACTION_IMPL_HH
#define ACTION_IMPL_HH

#include <libzork/vars/action.hh>

namespace libzork::vars
{

    class ActionImpl : public Action
    {
    public:
        ActionImpl(store::Store& store, std::string variable,
                std::string operation, int value);

        ~ActionImpl() override = default;

        void apply() const override;

    private:
        store::Store& store_;
        std::string variable_;
        std::string operation_;
        int value_;
    };

} // namespace libzork::vars
#endif // !ACTION_IMPL_HH
