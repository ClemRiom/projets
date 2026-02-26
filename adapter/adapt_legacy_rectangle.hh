#pragma once

#include "legacy_rectangle.hh"
#include "rectangle.hh"

class AdaptLegacyRectangle : public Rectangle
{
public:
    AdaptLegacyRectangle(LegacyRectangle& rect);
    virtual ~AdaptLegacyRectangle();
    virtual void print() const override;
    virtual unsigned area() const override;

private:
    LegacyRectangle& rect_;
};
