/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:31:08 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/23 12:46:12 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_x_value(const mlx_image_t *img,
						const t_img_params *img_p, int x_coord)
{
	return ((((double)x_coord / img->height) * img_p->x_spam)
		- (img_p->x_spam * img_p->x_displacement_perc));
}

static double	ft_y_value(const mlx_image_t *img,
						const t_img_params *img_p, int y_coord)
{
	return (-((((double)y_coord / img->width) * img_p->y_spam)
			- (img_p->y_spam * img_p->y_displacement_perc)));
}

void	draw_fractal(mlx_image_t *img, t_img_params *img_p)
{
	int				i;
	int				j;
	double			x;
	double			y;
	unsigned int	z;

	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			x = ft_x_value(img, img_p, i);
			y = ft_y_value(img, img_p, j);
			z = img_p->fractal_function(x, y);
			mlx_put_pixel(img, i, j, color_rgba(z, z, z, 255));
		}
	}
}
