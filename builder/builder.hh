#pragma once

#include "car.hh"

class Builder
{
public:
    Builder() = default;

    Car get_car() const;

protected:
    virtual std::unique_ptr<Wheel> get_wheel() const = 0;
    virtual std::unique_ptr<Engine> get_engine() const = 0;
    virtual std::unique_ptr<Body> get_body() const = 0;
};

class JeepBuilder : public Builder
{
protected:
    std::unique_ptr<Wheel> get_wheel() const override;
    std::unique_ptr<Engine> get_engine() const override;
    std::unique_ptr<Body> get_body() const override;
};

class NissanBuilder : public Builder
{
protected:
    std::unique_ptr<Wheel> get_wheel() const override;
    std::unique_ptr<Engine> get_engine() const override;
    std::unique_ptr<Body> get_body() const override;
};
