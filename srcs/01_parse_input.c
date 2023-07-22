/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:49:27 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 02:49:52 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parseInput(int argc, char* argv[])
{
	t_list	A;

	ft_list_init(&A);
	if (argc < 2)
	{
        	ft_printf("No input string provided.\n");
        	return (1);
	}
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		parseString(argv, &A);
	else if (argc > 2)
		parseArgs(argc, argv, &A);
	else
	{

	}
	return (&A);
}

int	parseString(char *argv[], t_list *A)
{
	char	**parsed_params;
	int	i;
	
	i = 0;
	parsed_params = ft_split(argv[1], ' ');
	while (parsed_params[i] != NULL)
	{
		ft_lstadd_back(&A, ft_lstnew(ft_atoi(parsed_params[i])));
		++i;
	}
	return (0);
}

int	parseArgs(int argc, char *argv[], t_list *A)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&A, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}


