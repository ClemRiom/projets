#pragma once
#include "vector.hh"

template <typename U>
std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec)
{
    for (const auto& elem : vec.vec_)
    {
        os << elem << " ";
    }
    os << std::endl;
    return os;
}
