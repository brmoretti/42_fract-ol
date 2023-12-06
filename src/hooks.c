/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:24:34 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/02 15:32:06 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(void *param)
{
	quit ((t_fractol *)param, EXIT_SUCCESS);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit(f, EXIT_SUCCESS);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		f->x_offset += 0.05 * f->x_spam;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		f->x_offset -= 0.05 * f->x_spam;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		f->y_offset += 0.05 * f->y_spam;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		f->y_offset -= 0.05 * f->y_spam;
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		zoom_in(f);
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		zoom_out(f);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		increase_resolution(f);
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		decrease_resolution(f);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	double		x_ratio;
	double		y_ratio;

	(void)xdelta;
	if (ydelta != 0)
	{
		f = param;
		mlx_get_mouse_pos(f->mlx, &(f->x_mouse), &(f->y_mouse));
		x_ratio = (((double)f->x_mouse / f->img->width) - 0.5) * 2;
		y_ratio = (((double)f->y_mouse / f->img->height) - 0.5) * 2;
	}
	if (ydelta > 0)
	{
		zoom_in(f);
		f->x_offset -= x_ratio * f->x_spam * 0.05;
		f->y_offset -= y_ratio * f->x_spam * 0.05;
	}
	else if (ydelta < 0)
	{
		zoom_out(f);
		f->x_offset += x_ratio * f->x_spam * 0.05;
		f->y_offset += y_ratio * f->x_spam * 0.05;
	}
}

void	mouse_hook(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_fractol	*f;
	double		x_ratio;
	double		y_ratio;

	(void)mods;
	f = param;
	if (button == MLX_MOUSE_BUTTON_LEFT
		&& (action == MLX_PRESS || action == MLX_REPEAT)
		&& f->fractal_function == julia && f->zoom == 1.0
		&& f->x_offset == 1.6 && f->y_offset == 1.6)
	{
		mlx_get_mouse_pos(f->mlx, &(f->x_mouse), &(f->y_mouse));
		x_ratio = (((double)f->x_mouse / f->img->width) - 0.5) * 2;
		y_ratio = (((double)f->y_mouse / f->img->height) - 0.5) * 2;
		f->x_seed = x_ratio * f->x_spam / 2;
		f->y_seed = -y_ratio * f->y_spam / 2;
	}
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		if (f->color_scheme == crazy_dynamic)
			f->color_scheme = black_and_white;
		else
			f->color_scheme++;
	}
}
