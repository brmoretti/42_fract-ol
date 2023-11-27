/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:40:29 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/27 14:27:39 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_fractol *f)
{
	f->fractal_function = mandelbrot;
	f->x_spam = 3;
	f->y_spam = 3;
	f->x_offset = 2.3;
	f->y_offset = 1.5;
}

static void	init_julia(t_fractol *f)
{
	f->fractal_function = julia;
	f->x_spam = 3.2;
	f->y_spam = 3.2;
	f->x_offset = 1.6;
	f->y_offset = 1.6;
	f->x_seed = 0.50;
	f->y_seed = 0.6;
	//f->x_seed = 0.766667;
	//f->y_seed = 0.090000;
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!f->mlx)
		return (errors(1));
	f->img = NULL;
	//init_mandelbrot(f);
	init_julia(f);
	f->zoom = 1.0;
	f->iters = ITERS;
	f->color_factor = color_factor(f);
}
