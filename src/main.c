/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:20:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/01 16:17:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_hook(void *param)
{
	t_fractol	*f;

	f = param;
	draw_fractal(f);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	init(&f, argc, argv);
	mlx_close_hook(f.mlx, &close_hook, &f);
	mlx_key_hook(f.mlx, &key_hook, &f);
	mlx_mouse_hook(f.mlx, &mouse_hook, &f);
	mlx_scroll_hook(f.mlx, &scroll_hook, &f);
	mlx_loop_hook(f.mlx, ft_hook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
