/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:01:33 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/30 17:48:42 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>


static int		hook(int key, t_fractal *fractal)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (key == 69)
		fractal->scale += 0.1;
	else if (key == 78 && fractal->scale)
		fractal->scale -= 0.1;
	mandebort(fractal);
	return (0);
}

int 	mouse(int button, int x, int y, t_fractal *fractal)
{
	printf("re %f\tim%f\n", fractal->x, fractal->y);
	fractal->x += 0.1;
	fractal->y += 0.1;
	mandebort(fractal);
	return (1);
}

void			ft_camera(t_fractal *fractal)
{

	mlx_mouse_hook(fractal->win_ptr, mouse, fractal);
	mlx_hook(fractal->win_ptr, 2, 0, hook, &fractal);
	mandebort(fractal);
}
