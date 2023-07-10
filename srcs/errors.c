/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:35:38 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/10 20:26:04 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit()
{
	write(1, "Error\n", 7);
	exit (0);
}

int	check_iput(char *argv[], int argc)
{
	int	index;

	if (!argc)
		error_exit();
	while (argc--)
	{
		while (argv[index] != 
		//only allow digets
		//atoi
	}

}

