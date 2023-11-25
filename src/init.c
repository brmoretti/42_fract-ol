/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:40:29 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/24 23:02:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_img_params *img_p)
{
	img_p->fractal_function = mandelbrot;
	img_p->x_spam = img_p->y_spam = 3;
	img_p->x_offset = 2.3;
	img_p->y_offset = 1.5;
}

void	init(t_items *items)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_img_params	*img_p;

	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		return (errors(1));
	img = NULL;
	img_p = malloc(sizeof(t_img_params));
	if (!img_p)
		return (errors(3));
	init_mandelbrot(img_p);
	img_p->zoom = 1.0;
	items->mlx = mlx;
	items->img = img;
	items->img_params = img_p;
}
