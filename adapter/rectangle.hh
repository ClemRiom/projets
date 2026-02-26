#pragma once

class Rectangle
{
public:
    virtual ~Rectangle()
    {}
    virtual void print() const = 0;
    virtual unsigned area() const = 0;
};
