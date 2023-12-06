/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:55:52 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/01 16:30:43 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(t_fractol *f, int error)
{
	if (error == missing_args)
		ft_putstr_fd("Missing args. Usage: "
			"./fractol <set_name> <real_seed> <imaginary_seed>\n", 1);
	else if (error == req_no_extra_args)
		ft_putstr_fd("This set requires no extra arguments\n", 1);
	else if (error == req_no_or_two_extra_args)
		ft_putstr_fd("This set requires either no extra arguments "
			"or exactly two extra arguments.\n", 1);
	else if (error == mlx_failure)
		ft_putstr_fd("Fail to create MLX instance\n", 1);
	else if (error == mlx_image_failure)
		ft_putstr_fd("Fail to create and place the image.\n,", 1);
	else if (error == invalid_args)
		ft_putstr_fd("Invalid argument. "
			"Valids: mandelbrot | julia | bship\n", 1);
	quit (f, EXIT_FAILURE);
}
