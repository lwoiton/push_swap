/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:49:27 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/10 14:28:29 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], t_list *a)
{
	if (argc < 2)
	{
		ft_printf("No input string provided.\n");
		return (-1);
	}
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		parse_string(argv, a);
	else if (argc > 2)
		parse_args(argc, argv, a);
	else
	{
	}
	determine_chunknr(a);
	return (0);
}

int	parse_string(char *argv[], t_list *a)
{
	char	**parsed_params;
	int		i;

	i = 0;
	parsed_params = ft_split(argv[1], ' ');
	while (parsed_params[i] != NULL)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(parsed_params[i])));
		++i;
	}
	return (0);
}

int	parse_args(int argc, char *argv[], t_list *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}
