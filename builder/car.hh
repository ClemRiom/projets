#pragma once

#include <array>
#include <iostream>
#include <memory>

#include "components.hh"

class Builder;

class Car
{
    friend Builder;

public:
    Car() = default;

    void print() const
    {
        std::cout << "body:" << body_->shape << '\n';
        std::cout << "engine horsepower:" << engine_->horsepower << '\n';
        std::cout << "wheel diameter:" << wheels_[0]->size << "\"\n";
    }

private:
    std::array<std::unique_ptr<Wheel>, 4> wheels_;
    std::unique_ptr<Engine> engine_ = nullptr;
    std::unique_ptr<Body> body_ = nullptr;
};
