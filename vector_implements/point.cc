#include "point.hh"

Point& Point::operator*=(int scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Point Point::operator*(int scalar) const
{
    auto new_point = Point{ *this };
    new_point *= scalar;
    return new_point;
}

Point operator*(int scalar, const Point& point)
{
    return point * scalar;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "{ " << point.x_ << ", " << point.y_ << " }";
    return os;
}
