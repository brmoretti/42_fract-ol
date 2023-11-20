/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:20:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/19 23:57:46 by bmoretti         ###   ########.fr       */
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

	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		printf("ERROR!");
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		printf("ERROR 1");
	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			new_i = (((double)i / img->height) * 3.0 - 2.3);
			new_j = -((((double)j / img->width)) * 3.0 - 1.5);
			m_number = mandelbrot(new_i, new_j);
			mlx_put_pixel(img, i, j, color_rgba(m_number, m_number, m_number, 255));
		}
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}
