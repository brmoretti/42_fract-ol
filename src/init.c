/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:40:29 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/29 19:35:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_fractol *f, int argc)
{
	if (argc > 2)
		errors(f, REQ_NO_EXTRA_ARGS);
	f->set = MANDELBROT;
	f->fractal_function = mandelbrot;
	f->x_spam = 3;
	f->y_spam = 3;
	f->x_offset = 2.3;
	f->y_offset = 1.5;
}

static void	init_julia(t_fractol *f, int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		errors(f, REQ_NO_OR_TWO_EXTRA_ARGS);
	f->set = JULIA;
	f->fractal_function = julia;
	f->x_spam = 3.2;
	f->y_spam = 3.2;
	f->x_offset = 1.6;
	f->y_offset = 1.6;
	if (argc == 2)
	{
		f->x_seed = -0.291892;
		f->y_seed = -0.016842;
	}
	else
	{
		f->x_seed = ft_atof(argv[2]);
		f->x_seed = ft_atof(argv[3]);
	}
}

void	which_fractal(t_fractol *f, int argc, char **argv)
{
	int	fractal;

	if (!ft_strncmp("mandelbrot", argv[1], ft_strlen("mandelbrot")))
		init_mandelbrot(f, argc);
	else if (!ft_strncmp("julia", argv[1], ft_strlen("julia")))
		init_julia(f, argc, argv);
}

void	init(t_fractol *f, int argc, char **argv)
{
	f->mlx = NULL;
	f->img = NULL;
	if (argc <= 1)
		return (errors(f, MISSING_ARGS));
	which_fractal(f, argc, argv);
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!f->mlx)
		return (errors(f, MLX_FAILURE));
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		errors (f, MLX_IMAGE_FAILURE);
	f->zoom = 1.0;
	f->iters = ITERS;
	f->color_factor = color_factor(f);
}
