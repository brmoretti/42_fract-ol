/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:24:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/26 14:04:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* julia_shift:
*	Changes the Julia calculation kr and ki values to get a different Julia
*	fractal shape. This function should be called when the user clicks on
*	a point on the sceen.
*/
// int	julia_shift(int x, int y, t_fractol *f)
// {
// 	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
// 	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
// 	render(f);
// 	return (0);
// }

// unsigned int	julia(double c_r, double c_i)
// {
// 	double			z_r_zero;
// 	double			z_r_one;
// 	double			z_i;
// 	unsigned int	n;

// 	z_r_zero = 0;
// 	z_i = 0;
// 	n = -1;
// 	while (++n < ITERS)
// 	{
// 		z_r_one = z_r_zero * z_r_zero - z_i * z_i + c_r - 0.766667;
// 		z_i = 2 * z_r_zero * z_i + c_i - 0.090000;
// 		if (z_r_one * z_r_one + z_i * z_i > 4.0)
// 			break ;
// 		z_r_zero = z_r_one;
// 	}
// 	return (n);
// }
unsigned int	julia(double c_r, double c_i)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < ITERS)
	{
		if ((c_i * c_i + c_r * c_r) > 4.0)
			break ;
		tmp = 2 * c_r * c_i - 0.090000;
		c_r = c_r * c_r - c_i * c_i - 0.766667;
		c_i = tmp;
		n++;
	}
	return (n);
}
