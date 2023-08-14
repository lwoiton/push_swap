/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:49:27 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/14 20:33:30 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], t_list *a)
{
	int	rtrn;

	rtrn = 0;
	if (argc < 2)
		rtrn = -1;
	else if (argc == 2)
		rtrn = parse_string(argv, a);
	else if (argc > 2)
		rtrn = parse_args(argc, argv, a);
	determine_chunknr(a);
	return (rtrn);
}

int	check_issorted(t_list *a)
{
	t_node	*curr_a;
	int		rtrn;

	curr_a = a->head;
	rtrn = 1;
	while (curr_a->next != a->head)
	{
		if (curr_a->content > curr_a->next->content)
			rtrn = 0;
		curr_a = curr_a->next;
	}
	return (rtrn);
}

int	check_isduplicated(t_list *a, int nbr)
{
	t_node	*curr_a;
	int	rtrn;

	curr_a = a->head;
	rtrn = 0;
	if (a->head == NULL)
		return (rtrn);
	while (curr_a->next != a->head)
	{
		if (curr_a->content == nbr)
			rtrn = -1;
		curr_a = curr_a->next;
	}
	return (rtrn);
}

int	parse_string(char *argv[], t_list *a)
{
	char	**parsed_params;
	int		i;
	int		rtrn;
	long		nbr;

	parsed_params = ft_split(argv[1], ' ');
	i = 0;
	rtrn = 0;
	while (parsed_params[i] != NULL && rtrn != -1)
	{
		if (check_isnumber(parsed_params[i]) == -1)
			rtrn = -1;
		nbr = ft_atoi(argv[i]);
		if (INT_MIN <= nbr && nbr <= INT_MAX && !check_isduplicated(a, nbr))
			ft_lstadd_back(a, ft_lstnew((int) nbr));
		else
			rtrn = -1;
		++i;
	}
	return (rtrn);
}

int	check_isnumber(char *str)
{
	int	i;
	int rtrn;

	i = 0;
	rtrn = 0;
	while (str[i] && rtrn != -1)
	{
		if(!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			rtrn = -1;
		i++;
	}
	return (rtrn);
}

int	parse_args(int argc, char *argv[], t_list *a)
{
	int	i;
	int	rtrn;
	long	nbr;

	i = 1;
	rtrn = 0;
	while (i < argc  && rtrn != -1)
	{
		if (check_isnumber(argv[i]) == -1)
			rtrn = -1;
		nbr = ft_atoi(argv[i]);
		if (INT_MIN <= nbr && nbr <= INT_MAX && !check_isduplicated(a, nbr))
			ft_lstadd_back(a, ft_lstnew((int) nbr));
		else
			rtrn = -1;
		i++;
	}
	return (rtrn);
}
