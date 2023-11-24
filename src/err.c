/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:55:52 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/24 08:18:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(unsigned int err_number)
{
	if (err_number == 1)
		puts("Fail to create MLX instance"); //forbidden function
	else if (err_number == 2)
		puts("Fail to create and place the image."); //forbidden function
	else if (err_number == 3)
		puts("Fail to allocate memmory"); //forbidden function
	exit(EXIT_FAILURE);
}
