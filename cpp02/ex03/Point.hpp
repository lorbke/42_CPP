/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:29 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 20:26:31 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
