#include <iostream>

#include "builder.hh"

int main()
{
    auto jeep_builder = JeepBuilder{};
    auto nissan_builder = NissanBuilder{};

    std::cout << "Jeep\n";
    auto jeep = jeep_builder.get_car();
    jeep.print();

    std::cout << '\n';

    std::cout << "Nissan\n";
    auto nissan = nissan_builder.get_car();
    nissan.print();

    return 0;
}
