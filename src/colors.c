/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:15:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/01 17:17:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	black_and_white_scheme(double nb)
{
	nb = 1 - nb;
	nb *= 255;
	return (color_rgba(nb, nb, nb, 255));
}

double	golden_ratio_scheme(double nb)
{
	int	r;
	int	g;
	int	b;

	r = 1.61803398875 * nb * 255;
	g = nb * 255;
	b = (r + g) % 255;
	return (color_rgba(r, g, b, 255));
}

double	crazy_scheme(double nb)
{
	int	r;
	int	g;
	int	b;

	nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * 5;
	r = (sin(nb) + 1) / 2 * 255;
	g = (int)nb % 255;
	b = (int)(nb / 2) % 255;
	return (color_rgba(r, g, b, 255));
}

double	crazy_dynamic_scheme(double nb)
{
	int		r;
	int		g;
	int		b;
	double	time;

	time = mlx_get_time();
	if (time > 10000)
		time = 10000;
	nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * mlx_get_time();
	r = (sin(nb) + 1) / 2 * 255;
	g = (int)nb % 255;
	b = (int)(nb / 1.61803398875) % 255;
	return (color_rgba(r, g, b, 255));
}

double	scheme_selector(double nb, int color_scheme)
{
	if (color_scheme == black_and_white)
		return (black_and_white_scheme(nb));
	if (color_scheme == golden_ratio)
		return (golden_ratio_scheme(nb));
	if (color_scheme == crazy)
		return (crazy_scheme(nb));
	if (color_scheme == crazy_dynamic)
		return (crazy_dynamic_scheme(nb));
	return (-1);
}
