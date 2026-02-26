#pragma once

#include <ostream>
class Point
{
public:
    Point(int x, int y)
        : x_{ x }
        , y_{ y }
    {}

    Point(const Point& p)
    {
        x_ = p.x_;
        y_ = p.y_;
    }

    Point& operator*=(int scalar);

    Point operator*(int scalar) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
    int x_;
    int y_;
};

Point operator*(int scalar, const Point& point);
