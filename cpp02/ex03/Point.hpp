
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
				Point();
				Point(const float x, const float y);
				Point(const Point& original);
		Point&	operator=(Point& original);
				~Point();
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
