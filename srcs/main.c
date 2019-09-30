/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:20:30 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/30 17:01:37 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void	inc_mlx(t_fractal *fractal)
{
	int g;

	g = 1;
	if (!(fractal->mlx_ptr = mlx_init()))
		error("mlx = NULL");
	if (!(fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH,
			HIGHT, "Fractal")))
		error("windows = NULL");
	if (!(fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HIGHT)))
		error("image = NULL");
	if (!(fractal->map = (int*)mlx_get_data_addr(fractal->img_ptr, &g,
			&fractal->size_line, &fractal->endian)))
		error("data_addr = NULL");
	fractal->scale = 450;
	fractal->max_iteration = 50;
}



int		main(int a, char **b)
{
	t_fractal	fractal;

	ft_bzero(&fractal, sizeof(fractal));
	inc_mlx(&fractal);
	fractal.x = 0;
	fractal.y = 0;
	ft_camera(&fractal);


	mlx_loop(fractal.mlx_ptr);
	return (0);
}
