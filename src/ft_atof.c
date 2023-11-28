/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:25 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/27 19:02:11 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(const char *nptr)
{
	int		sign;
	double	nb;
	int		divider;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' && ('0' <= nptr[1] && nptr[1] <= '9'))
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && '0' <= *nptr && *nptr <= '9')
		nb = nb * 10 + (*(nptr++) - '0');
	if (*nptr == '.')
		nptr++;
	divider = 10;
	while (*nptr && '0' <= *nptr && *nptr <= '9')
	{
		nb += (double)(*(nptr++) - '0') / divider;
		divider *= 10;
	}
	return (sign * nb);
}
