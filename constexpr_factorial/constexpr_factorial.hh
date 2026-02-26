#include <chrono>
#include <iostream>

unsigned long long factorial(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

constexpr unsigned long long c_factorial(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * c_factorial(n - 1);
}
