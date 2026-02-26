#include <chrono>
#include <iostream>
#include "constexpr_factorial.hh"

int main()
{
    const unsigned int n = 30;
    // Tracking time of non-constexpr fibonacci
    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = factorial(n);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;
    std::cout << "Non-constexpr fibonacci of " << n << " = " << result
    << std::endl;
    std::cout << "Execution time : " << duration.count() << " ms" << std::endl;
    // Tracking time of constexpr fibonacci
    start_time = std::chrono::high_resolution_clock::now();
    // Store the constexpr result in a variable.
    constexpr unsigned long long result_constexpr = c_factorial(n);
    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;
    std::cout << "Constexpr fibonacci of " << n << " = " << result_constexpr
    << std::endl;
    std::cout << "Execution time : " << duration.count() << " ms" << std::endl;
    return 0;
}
