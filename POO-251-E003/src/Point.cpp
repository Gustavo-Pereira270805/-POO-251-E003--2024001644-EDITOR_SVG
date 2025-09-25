#include "editor/Point.h"

Point::Point(double x_val, double y_val) : x(x_val), y(y_val){}

Point Point::operator+(const Point& p)const{
    return Point(this->x + p.x, this->y + p.y);
}

Point Point::operator-(const Point& p)const{
    return Point(this->x - p.x, this->y - p.y);
}

Point Point::operator==(const Point& p)const{
    return Point(this->x == p.x, this->y == p.y);
}