/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:29 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 20:29:27 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
				Point();
				Point(float const x, float const y);
				Point(Point const& original);
		Point&	operator=(Point& original);
				~Point();
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif
