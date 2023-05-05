/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:41 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 21:03:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	isClockwise(Point const a, Point const b, Point const c)
{
	Fixed	cross_product = (b.getX() - a.getX()) * (c.getY() - a.getY())
		- (b.getY() - a.getY()) * (c.getX() - a.getX());

	if (cross_product < 0)
		return (true);
	return (false);
}

static bool	isInnerSide(const Point a, const Point b, const Point c, bool clockwise)
{
	Fixed	scalar_product = (c.getY() - b.getY()) * (a.getX() - b.getX())
		+ (c.getX() * -1 + b.getX()) * (a.getY() - b.getY());

	if (clockwise == true)
		return (scalar_product >= 0);
	return (scalar_product <= 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	clockwise = isClockwise(a, b, c);

	bool	sideAB = isInnerSide(a, b, point, clockwise);
	bool	sideBC = isInnerSide(b, c, point, clockwise);
	bool	sideCA = isInnerSide(c, a, point, clockwise);

	if (sideAB == true && sideBC == true && sideCA == true)
		return (true);
	return (false);
}
