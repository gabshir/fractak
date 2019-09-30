/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandebort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:32:55 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/30 18:23:02 by gabshire         ###   ########.fr       */
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

void	mandebort(t_fractal	*fractal)
{
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	int			x;
	int 		y;
	int 		iteration;


	min.im = -2.;
	max.im = 2.;
	min.re = ((max.im - min.im) * WIDTH / HIGHT) / -2.;
	max.re = min.re * -1.;
	factor = init_complex((max.re - min.re) / (WIDTH - 1),
			(max.im - min.im) / (HIGHT - 1));
	ft_bzero(fractal->map, sizeof(int) * WIDTH * HIGHT);
	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		c.im = max.im - y * factor.im;
		fractal->y = c.im;
		while (x < WIDTH)
		{
			c.re = min.re + x * factor.re;
			fractal->x = c.re;
			z = init_complex(c.re, c.im);
			iteration = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0 && iteration < fractal->max_iteration)
			{
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,2.0 * z.re * z.im + c.im);
				iteration++;
			}
			if (HIGHT * WIDTH > y * WIDTH + x)
				fractal->map[y * WIDTH + x] = 0xf0f0f + iteration * 1050;
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}
