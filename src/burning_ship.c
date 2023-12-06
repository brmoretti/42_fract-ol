/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:34:55 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/01 17:17:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	burning_ship(double c_r, double c_i, void *vars)
{
	int			n;
	double		tmp;
	t_fractol	*f;
	double		real;
	double		imaginary;

	real = -c_r;
	imaginary = -c_i;
	f = (t_fractol *)vars;
	n = 0;
	while (n < f->iters)
	{
		if ((c_i * c_i + c_r * c_r) > 4.0)
			break ;
		tmp = c_i * c_i - c_r * c_r + real;
		c_i = fabs(2 * c_r * c_i) + imaginary;
		c_r = tmp;
		n++;
	}
	return (n);
}
