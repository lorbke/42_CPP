
#include "Point.hpp"

static bool	checkSide(const Point a, const Point b, const Point c)
{
	return ((c.getY() - b.getY()) * (a.getX() - b.getX())
		+ (c.getX() * -1 + b.getX()) * (a.getY() - b.getY())
		>= 0);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	sideAB = checkSide(a, b, point);
	bool	sideBC = checkSide(b, c, point);
	bool	sideCA = checkSide(c, a, point);

	if (sideAB == true && sideBC == true && sideCA == true)
		return (true);
	return (false);
}
