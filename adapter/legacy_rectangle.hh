#pragma once

class LegacyRectangle
{
public:
    LegacyRectangle(int x1, int y1, int x2, int y2);
    unsigned compute_area() const;
    int get_x1() const;
    int get_x2() const;
    int get_y1() const;
    int get_y2() const;

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
};
