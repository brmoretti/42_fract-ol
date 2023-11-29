/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:24:06 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/29 15:56:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	color_factor(t_fractol *f)
{
	return (1 / (f->iters + 1));
}

double	golden_ratio(double nb)
{
	int	r;
	int g;
	int b;

	r = 1.61803398875 * nb * 255;
	g = nb * 255;
	b = (r + g) % 255;
	return (color_rgba(r, g, b, 255));
}
