/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:20:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/24 16:50:30 by bmoretti         ###   ########.fr       */
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

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);

// }

void keyhook(mlx_key_data_t keydata, void* param)
{
	t_items	*item;

	item = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(item->mlx);
		mlx_terminate(item->mlx);
		free (item->img_params);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		item->img_params->x_offset += 0.05;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		item->img_params->x_offset -= 0.05;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		item->img_params->y_offset += 0.05;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		item->img_params->y_offset -= 0.05;
}

void scrollhook(double xdelta, double ydelta, void* param)
{
	t_items	*item;

	item = param;
	if (ydelta > 0)
	{
		item->img_params->x_spam *= 0.99;
		item->img_params->y_spam *= 0.99;
	}
	else if (ydelta < 0)
	{
		item->img_params->x_spam *= 1.01;
		item->img_params->y_spam *= 1.01;
	}
}

static void ft_hook(void* param)
{
	t_items	*items;
	mlx_image_t	*img;
	mlx_t	*mlx;

	items = param;
	mlx = items->mlx;
	img = items->img;
	if (img)
		mlx_delete_image(mlx, img);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (errors(2));
	items->img = img;
	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	draw_fractal(items->img, items->img_params);
}

int	main(void)
{
	t_items	items;

	init(&items);
	mlx_get_mouse_pos(items.mlx, &(items.x_mouse), &(items.y_mouse));
	printf("x: %d y: %d\n", items.x_mouse, items.y_mouse);
	mlx_key_hook(items.mlx, &keyhook, &items);
	mlx_scroll_hook(items.mlx, &scrollhook, &items);
	mlx_loop_hook(items.mlx, ft_hook, &items);
	mlx_loop(items.mlx);
	mlx_terminate(items.mlx);
	free (items.img_params);
	return (EXIT_SUCCESS);
}
