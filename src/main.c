/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:20:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/23 15:06:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	main(int ac, char **av)
// {
// 	t_data	data;

// 	init(&data, av, ac);
// 	mlx_key_hook(data.mlx, &key_hook, &data);
// 	mlx_scroll_hook(data.mlx, &scroll_hook, &data);
// 	mlx_close_hook(data.mlx, &close_program, &data);
// 	mlx_image_to_window(data.mlx, data.img, 0, 0);
// 	mlx_loop_hook(data.mlx, &render, &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// 	return (0);
// }

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				i;
	int				j;
	double			new_i;
	double			new_j;
	unsigned int	m_number;
	t_img_params	img_p;

	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		printf("ERROR!");
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		printf("ERROR 1");
	img_p.fractal_function = mandelbrot;
	img_p.x_spam = img_p.y_spam = 3;
	img_p.x_displacement_perc = 0.75;
	img_p.y_displacement_perc = 0.5;
	draw_fractal(img, &img_p);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}
