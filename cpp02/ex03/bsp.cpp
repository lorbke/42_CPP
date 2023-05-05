/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:41 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 20:26:43 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	checkSide(const Point a, const Point b, const Point c)
{
	return ((c.getY() - b.getY()) * (a.getX() - b.getX())
		+ (c.getX() * -1 + b.getX()) * (a.getY() - b.getY())
		>= 0);
}

// @todo order points counter clockwise before checking sides
bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	sideAB = checkSide(a, b, point);
	bool	sideBC = checkSide(b, c, point);
	bool	sideCA = checkSide(c, a, point);

	if (sideAB == true && sideBC == true && sideCA == true)
		return (true);
	return (false);
}
