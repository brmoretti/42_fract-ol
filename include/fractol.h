/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:17:28 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/29 14:54:36 by bmoretti         ###   ########.fr       */
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

# define WIDTH 600
# define HEIGHT 600
# define ITERS 200

enum e_errors
{
	MISSING_ARGS,
	TOO_MANY_ARGS,
	REQ_NO_EXTRA_ARGS,
	REQ_NO_OR_TWO_EXTRA_ARGS,
	MLX_FAILURE,
	MLX_IMAGE_FAILURE
};

enum	e_set
{
	MANDELBROT,
	JULIA
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
	int				set;
	unsigned int	(*fractal_function)(double, double, void*);
}	t_fractol;

uint32_t		color_rgba(int r, int g, int b, int a);
double			color_factor(t_fractol *f);

double			ft_atof(const char *nptr);

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

double			golden_ratio(double nb);

#endif
