/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:15:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/29 19:28:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	black_and_white(double nb)
{
	nb = 1 - nb;
	nb *= 255;
	return(color_rgba(nb, nb, nb, 255));
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

double	crazy(double nb)
{
	int	r;
	int g;
	int b;

	nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * 5;
	r = sin(nb) * 255;
	g = (int)nb % 255;
	b = (int)(nb / 2) % 255;
	return (color_rgba(r, g, b, 255));
}
