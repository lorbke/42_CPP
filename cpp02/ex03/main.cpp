/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:21 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 17:12:47 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "MLX42.h"

#define	WIDTH	400
#define	HEIGHT	400

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	draw_triangle(Point a, Point b, Point c)
{
	mlx_t		*mlx = mlx_init(WIDTH, HEIGHT, "Triangle", false);
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);

	mlx_image_to_window(mlx, image, 0, 0);
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			Point	point(i, j);
			if (bsp(a, b, c, point))
				mlx_put_pixel(image, i, j, 0xFFFFFFFF);
		}	
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	main( void )
{
	Point	a1(600, 0);
	Point	b1(0, 400);
	Point	c1(400, 0);

	Point	b2(0, 0);
	Point	c2(0, 400);
	Point	a2(400, 0);

	draw_triangle(a2, b2, c2);
	draw_triangle(a1, b1, c1);

	return 0;
}
