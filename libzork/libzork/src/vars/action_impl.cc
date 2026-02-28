#include "vars/action_impl.hh"

#include "exceptions.hh"

namespace libzork::vars
{

    ActionImpl::ActionImpl(store::Store& store, std::string variable,
                           std::string operation, int value)
        : store_(store), variable_(std::move(variable)),
          operation_(std::move(operation)), value_(value) {}

    void ActionImpl::apply() const
    {
        int current_val = store_.get_variable(variable_);

        if (operation_ == "assign") {
            store_.set_variable(variable_, value_);
        } 
        else if (operation_ == "add") {
            store_.set_variable(variable_, current_val + value_);
        } 
        else if (operation_ == "sub") {
            store_.set_variable(variable_, current_val - value_);
        } 
        else {
            throw std::invalid_argument("Unknown operation: " + operation_);
        }
    }

    std::unique_ptr<Action> make_action(store::Store& store,
                                        const std::string& variable,
                                        const std::string& action, int value)
    {
        return std::make_unique<ActionImpl>(store, variable, action, value);
    }

} // namespace libzork::vars
