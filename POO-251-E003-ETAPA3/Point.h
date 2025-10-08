#pragma once

class Point{
    public:
        double x = 0.0;
        double y = 0.0;

        Point(double x_val = 0.0, double y_val = 0.0);

        Point operator+(const Point& p)const;
        Point operator-(const Point& p)const;
        Point operator==(const Point& p)const;
};