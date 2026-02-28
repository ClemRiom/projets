#include "vars/condition_impl.hh"

#include <algorithm>
#include <map>

#include "exceptions.hh"

namespace libzork::vars
{
    ConditionImpl::ConditionImpl(const store::Store& store, std::string variable,
                                 std::string comparison, int value)
        : store_(store), variable_(std::move(variable)),
          comparison_(std::move(comparison)), value_(value) {}

    bool ConditionImpl::apply() const
    {
        int current_val = store_.get_variable(variable_);

        if (comparison_ == "equal") return current_val == value_;
        if (comparison_ == "not_equal") return current_val != value_;
        if (comparison_ == "greater") return current_val > value_;
        if (comparison_ == "lower") return current_val < value_;
        if (comparison_ == "greater_equal") return current_val >= value_;
        if (comparison_ == "lower_equal") return current_val <= value_;

        throw std::invalid_argument("Unknown comparison: " + comparison_);
    }

} // namespace libzork::vars
