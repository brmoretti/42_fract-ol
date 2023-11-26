/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:40:29 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/26 16:53:44 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_fractol *f)
{
	f->fractal_function = mandelbrot;
	f->x_spam = f->y_spam = 3;
	f->x_offset = 2.3;
	f->y_offset = 1.5;
}

static void	init_julia(t_fractol *f)
{
	f->fractal_function = julia;
	f->x_spam = f->y_spam = 3;
	f->x_offset = 2.3;
	f->y_offset = 1.5;
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
}
