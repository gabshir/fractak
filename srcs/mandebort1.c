/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandebort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:32:55 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/30 16:09:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

t_complex init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	drow_point(double a, double b, t_fractal *fractal, int iteration)
{
	int c;
	int a1;
	int b1;

	c = WIDTH * HIGHT / 2;
//	a *= fractal->scale;
//	b *= fractal->scale;
	a1 = (int)a;
	b1 = (int)(b * WIDTH);
	if (c + b1 + a1 < WIDTH * HIGHT && c + b1 + a1 > 0)
		fractal->map[c + b1 + a1] = 0xff * iteration * 200;
}

void	mandebort(t_fractal	*fractal)
{
	double a;
	double b;
	double x_temp;
	double y_temp;
	double x;
	double y;
	int 	iteration;

	a = -2.0;
	ft_bzero(fractal->map, sizeof(int) * WIDTH * HIGHT);
	while (a < 2.0)
	{
		b = -2.0;
		while (b < 2.0)
		{
			x = a;
			y = b;
			iteration = 0;
			while (iteration < fractal->max_iteration && x * x + y * y <= 4)
			{
				x_temp = x * x - y * y + a;
				y_temp = 2 * x * y + b;
				x = x_temp;
				y = y_temp;
				++iteration;
			}
			if (iteration == fractal->max_iteration)
				drow_point(a, b, fractal, iteration);
			b += 0.001;
		}
		a += 0.001;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}
