/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:20:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/26 23:33:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (errors(2));
	draw_fractal(f);
}

int	main(void)
{
	t_fractol	f;

	init(&f);
	mlx_loop_hook(f.mlx, ft_hook, &f);
	mlx_key_hook(f.mlx, &keyhook, &f);
	mlx_scroll_hook(f.mlx, &scrollhook, &f);
	mlx_close_hook(f.mlx, &closehook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
