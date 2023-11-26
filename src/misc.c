/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:40:09 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/26 16:46:40 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quit(mlx_t	*mlx)
{
	mlx_close_window(mlx);
	mlx_terminate(mlx);
	exit (EXIT_SUCCESS);
}

void	zoom_in(t_fractol *f)
{
	f->x_spam *= 0.99;
	f->y_spam *= 0.99;
	f->zoom /= 0.99;
	f->x_offset *= 1;
	f->y_offset	*= 1;
}

void	zoom_out(t_fractol *f)
{
	f->x_spam *= 1.01;
	f->y_spam *= 1.01;
	f->zoom /= 1.01;
	f->x_offset *= 1.01;
	f->y_offset	*= 1.01;
}
