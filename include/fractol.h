/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:17:28 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/01 02:44:37 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"

# define WIDTH 200
# define HEIGHT 200
# define ITERS 200

enum e_errors
{
	missing_args,
	too_many_args,
	req_no_extra_args,
	req_no_or_two_extra_args,
	mlx_failure,
	mlx_image_failure
};

enum	e_set //yet unused
{
	MANDELBROT,
	JULIA
};

enum	e_color_scheme
{
	black_and_white,
	golden_ratio,
	crazy,
	crazy_dynamic
};

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int32_t			x_mouse;
	int32_t			y_mouse;
	double			x_spam;
	double			y_spam;
	double			x_offset;
	double			y_offset;
	double			x_seed;
	double			y_seed;
	double			zoom;
	double			iters;
	double			color_factor;
	int				color_scheme;
	int				set; //unused
	unsigned int	(*fractal_function)(double, double, void*);
}	t_fractol;

uint32_t		color_rgba(int r, int g, int b, int a);
double			color_factor(t_fractol *f);
double			scheme_selector(double nb, int color_scheme);

unsigned int	mandelbrot(double c_r, double c_i, void *vars);
unsigned int	julia(double c_r, double c_i, void *vars);

void			close_hook(void *param);
void			key_hook(mlx_key_data_t keydata, void *param);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			mouse_hook(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);
void			resize_hook(int32_t width, int32_t height, void *param);

void			draw_fractal(t_fractol	*f);
void			quit(t_fractol *f, int exit_type);
void			errors(t_fractol *f, int error);
void			init(t_fractol *f, int argc, char **argv);
void			zoom_in(t_fractol *f);
void			zoom_out(t_fractol *f);
void			increase_resolution(t_fractol *f);
void			decrease_resolution(t_fractol *f);

double			black_and_white_scheme(double nb);
double			golden_ratio_scheme(double nb);
double			crazy_scheme(double nb);

#endif
