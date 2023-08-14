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

int	is_intput_sorted(t_list *a)
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

int	parse_string(char *argv[], t_list *a)
{
	char	**parsed_params;
	int		i;
	int		rtrn;

	parsed_params = ft_split(argv[1], ' ');
	i = 0;
	rtrn = 0;
	while (parsed_params[i] != NULL && rtrn != -1)
	{
		if (check_input(parsed_params[i]) == -1)
			rtrn = -1;
		if (check_max_min_int(argv[i]) == -1)
			rtrn = -1;
		ft_lstadd_back(a, ft_lstnew(ft_atoi(parsed_params[i])));
		++i;
	}
	return (rtrn);
}

int	check_input(char *str)
{
	int	i;
	int rtrn;

	i = 0;
	rtrn = 0;
	while (str[i] && rtrn != -1)
	{
		if(!ft_isdigit(str[i]) && str[i] != '-')
			rtrn = -1;
		i++;
	}
	return (rtrn);
}

int	check_max_min_int(char *nptr)
{
	int	n;
	long long	nbr;

	n = 1;
	nbr = 0;
	while (*nptr && (*nptr == 32 || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-')
	{
		n = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (long long)(*nptr - 48);
		nptr++;
	}
	if (n == 1 && nbr > 2147483647)
		return (-1);
	else if (n == -1 && nbr > 2147483648)
		return (-1);
	return (0);
}

int	parse_args(int argc, char *argv[], t_list *a)
{
	int	i;
	int	rtrn;

	i = 1;
	rtrn = 0;
	while (i < argc  && rtrn != -1)
	{
		if (check_input(argv[i]) == -1)
			rtrn = -1;
		if (check_max_min_int(argv[i]) == -1)
			rtrn = -1;
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (rtrn);
}
