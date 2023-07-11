/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:35:38 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/11 17:58:54 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit()
{
	write(1, "Error\n", 7);
	exit (0);
}

int	input_check(char *argv[], int argc)
{
	int	index;

	if (!argc)
		error_exit();
	while (argv[index])
		ft_putstr_fd(1, argv[index]);
	return (1);
}

