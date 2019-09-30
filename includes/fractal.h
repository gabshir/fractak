/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:48:43 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/30 17:53:54 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "/usr/local/include/mlx.h"
# include <math.h>
#include <stdio.h>
# define WIDTH 1920
# define HIGHT 1080
# define ASPECT_RATIO WIDTH / HEIGHT

void	error(char *str);



typedef struct	s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*map;
	int			size_line;
	int			endian;
	int			scale;
	int 		max_iteration;
	double 		x;
	double 		y;
}				t_fractal;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

void	mandebort(t_fractal	*fractal);
void			ft_camera(t_fractal *fractal);

#endif
