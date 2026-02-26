#pragma once

#include <string>

struct Wheel
{
    Wheel(int size_init)
        : size(size_init)
    {}

    int size;
};

struct Engine
{
    Engine(int horsepower_init)
        : horsepower(horsepower_init)
    {}

    int horsepower;
};

struct Body
{
    Body(const std::string& shape_init)
        : shape(shape_init)
    {}

    std::string shape;
};
