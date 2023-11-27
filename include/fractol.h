/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:17:28 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/27 14:10:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "MLX42/MLX42.h"

# define WIDTH 300
# define HEIGHT 300
# define ITERS 200

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
	unsigned int	(*fractal_function)(double, double, void*);
}	t_fractol;

uint32_t		color_rgba(int r, int g, int b, int a);
double			color_factor(t_fractol *f);

unsigned int	mandelbrot(double c_r, double c_i, void *vars);
unsigned int	julia(double c_r, double c_i, void *vars);

void			closehook(void *param);
void			keyhook(mlx_key_data_t keydata, void *param);
void			scrollhook(double xdelta, double ydelta, void *param);

void			draw_fractal(t_fractol	*f);
void			quit(mlx_t	*mlx);
void			errors(unsigned int err_number);
void			init(t_fractol *f);
void			zoom_in(t_fractol *f);
void			zoom_out(t_fractol *f);
void			increase_resolution(t_fractol *f);
void			decrease_resolution(t_fractol *f);

#endif
