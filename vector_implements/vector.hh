#pragma once

#include <concepts>
#include <iostream>
#include <vector>


template <typename T, typename U>
concept Mul = requires(T t, U u) {
    { t * u } -> std::convertible_to<T>;
    { t *= u} -> std::same_as<T&>;
};

template <typename T>
concept Summable = requires(T t1, T t2) {
    { t1 + t2 } -> std::convertible_to<T>;
};

template <typename T>
class MyVector
{
public:
    MyVector() = default;

    MyVector(const std::vector<T>& v)
        : vec_{ v }
    {}
    // Multiplies all the element of the array by the scalar and return a new
    // MyVector
    template <typename U>
        requires Mul<T, U>
        MyVector<T>
    operator*(const U& scalar)
    {
        MyVector<T> res = *this;
        res *= scalar;
        return res;
    }

    // Multiplies all the element of the array by the scalar in place
    template <typename U>
        requires Mul<T, U>
        MyVector<T>
    & operator*=(const U& scalar)
    {
        for (auto& e: vec_) {
            e *= scalar;
        }
        return *this;
    }

    // Sums all the element in the vector to the init value, and returns the
    // result
    T reduce(T init) const requires Summable<T>
    {
        T sum = init;
        for (const auto& e: vec_) {
            sum = sum + e;
        }
        return sum;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec);

private:
    std::vector<T> vec_;
};

#include "vector.hxx"
