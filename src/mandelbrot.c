/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:16:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/27 13:26:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(double c_r, double c_i, void *vars)
{
	unsigned int	n;
	double			z_r;
	double			z_i;
	double			tmp;
	t_fractol		*f;

	f = vars;
	z_r = 0;
	z_i = 0;
	n = -1;
	while (++n < f->iters)
	{
		if ((z_r * z_r + z_i * z_i) > 4.0)
			break ;
		tmp = 2 * z_r * z_i + c_i;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = tmp;
	}
	return (n);
}
