/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:08 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/26 15:03:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_x_value(const t_fractol *f, int x_coord)
{
	return ((((double)x_coord / f->img->width) * f->x_spam)
		- f->x_offset);
}

static double	ft_y_value(const t_fractol *f, int y_coord)
{
	return (-((((double)y_coord / f->img->height) * f->y_spam)
			- f->y_offset));
}

void	draw_fractal(t_fractol	*f)
{
	int				i;
	int				j;
	double			x;
	double			y;
	unsigned int	z;

	i = -1;
	while (++i < f->img->width)
	{
		j = -1;
		while (++j < f->img->height)
		{
			x = ft_x_value(f, i);
			y = ft_y_value(f, j);
			z = f->fractal_function(x, y);
			mlx_put_pixel(f->img, i, j, color_rgba((z * z % 255), (2 * z) % 255, z % 255, 255));
		}
	}
}
