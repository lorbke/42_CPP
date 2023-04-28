
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

// @todo probably wrong
Point&	Point::operator=(Point& original)
{
	return (original);
}

Point::Point(const Point& original) : _x(original._x), _y(original._y)
{
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
