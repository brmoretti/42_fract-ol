/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:16:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/19 22:51:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(double c_r, double c_i)
{
	double			z_r_zero;
	double			z_r_one;
	double			z_i;
	unsigned int	n;

	z_r_zero = 0;
	z_i = 0;
	n = -1;
	while (++n < ITERS)
	{
		z_r_one = z_r_zero * z_r_zero - z_i * z_i + c_r;
		z_i = 2 * z_r_zero * z_i + c_i;
		if (z_r_one * z_r_one + z_i * z_i > 4.0)
			break ;
		z_r_zero = z_r_one;
	}
	return (n);
}
