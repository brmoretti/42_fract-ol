/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:24:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/27 13:27:04 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(double c_r, double c_i, void *vars)
{
	int			n;
	double		tmp;
	t_fractol	*f;

	f = vars;
	n = 0;
	while (n < f->iters)
	{
		if ((c_i * c_i + c_r * c_r) > 4.0)
			break ;
		tmp = 2 * c_r * c_i - f->y_seed;
		c_r = c_r * c_r - c_i * c_i - f->x_seed;
		c_i = tmp;
		n++;
	}
	return (n);
}
