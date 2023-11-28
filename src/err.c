/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:55:52 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/28 11:58:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(t_fractol *f, int error)
{
	if (error == MISSING_ARGS)
		ft_putstr_fd("Missing args. Usage: "
			"./fractol <set_name> <real_seed> <imaginary_seed>\n", 1);
	else if (error == REQ_NO_EXTRA_ARGS)
		ft_putstr_fd("This set requires no extra arguments\n", 1);
	else if (error == REQ_NO_OR_TWO_EXTRA_ARGS)
		ft_putstr_fd("This set requires either no extra arguments "
			"or exactly two extra arguments.\n", 1);
	else if (error == MLX_FAILURE)
		ft_putstr_fd("Fail to create MLX instance\n", 1);
	else if (error == MLX_IMAGE_FAILURE)
		ft_putstr_fd("Fail to create and place the image.\n,", 1);
	quit (f, EXIT_FAILURE);
}
