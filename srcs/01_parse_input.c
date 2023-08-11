/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:49:27 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/10 16:09:03 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], t_list *a)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (-1);
	}
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		parse_string(argv, a);
	else if (argc > 2)
		parse_args(argc, argv, a);
	else
	{
	}
	//determine if input is already sorted
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
		if (check_input(parsed_params[i]) == -1)
			return (-1);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(parsed_params[i])));
		++i;
	}
	return (0);
}

int	check_input(char *str)
{
	while (*str)
	{
		if(ft_isdigit(*str))
		{}
		else
		{
			ft_printf("Error\n");
			return (-1);
		}
		str++;
	}
	return (0);
}

// isDiget and - minus
// is in MAXINT and minINT range
// check if input is already sorted

int	parse_args(int argc, char *argv[], t_list *a)
{
	int	i;

	i = 1;
	while (i < argc  && check_input(argv[i]))
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}
