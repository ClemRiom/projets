#pragma once

template<typename T, typename U = T>
concept impl_basic_op = requires(T t, U u) {
    +a;
    +b;
    a + b;
    a - b;
    a * b;
    a / b;
};

template <typename T, typename U = T>
concept impl_modulo = requires(T a, U b) {
    a % b;
};

template <typename T, typename U = T>
concept impl_bitwise_op = requires(T a, U b) {
    ~a;
    a & b;
    a | b;
    a ^ b;
    a << b;
    a >> b;
};

template <typename T, typename U = T>
concept impl_arith_op = impl_basic_op<T, U> && impl_modulo<T, U> && impl_bitwise_op<T, U>;
