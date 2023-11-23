/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:17:28 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/23 12:48:12 by bmoretti         ###   ########.fr       */
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
# define ITERS 255

typedef struct s_img_params
{
	double			x_spam;
	double			y_spam;
	double			x_displacement_perc;
	double			y_displacement_perc;
	unsigned int	(*fractal_function)(double, double);
} t_img_params;

uint32_t		color_rgba(int r, int g, int b, int a);

unsigned int	mandelbrot(double c_r, double c_i);
void	draw_fractal(mlx_image_t *img, t_img_params *img_p);

#endif
