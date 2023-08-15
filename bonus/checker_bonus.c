/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:34:22 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/15 17:06:19 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_input(int argc, char *argv[], t_list *a)
{
	if (parse_input(argc, argv, a) == -1)
	{
		free_list(a);
		return (-1);
	}
	if (check_issorted(a) == 1)
	{
		free_list(a);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*line;
	t_list	a;
	t_list	b;

	ft_list_init(&a, 0);
	ft_list_init(&b, 0);
	if (test_input(argc, argv, a) == -1 || test_input(argc, argv, b) == 1)
		return (-1);
	print_stacks(&a, &b);
	line = "s";
	while (line != NULL)
	{
		line = get_next_line(0);
  		if (ft_strncmp(line, "sa", 2) == 0)
			swap(&a);
		else if (ft_strncmp(line, "sb", 2) == 0)
			swap(&b);
		else if (ft_strncmp(line, "ss", 2) == 0)
			swap2(&a, &b, 0);
		else if (ft_strncmp(line, "pa", 2) == 0)
			push(&a, &b);
		else if (ft_strncmp(line, "pb", 2) == 0)
			push(&b, &a);
		else if (ft_strncmp(line, "ra", 2) == 0)
			rotate1(&a);
		else if (ft_strncmp(line, "rb", 2) == 0)
			rotate1(&b);
		else if (ft_strncmp(line, "rr", 2) == 0)
			rotate2(&a, &b);
		else if (ft_strncmp(line, "rra", 3) == 0)
			reverse_rotate1(&a);
		else if (ft_strncmp(line, "rrb", 3) == 0)
			reverse_rotate1(&b);
		else if (ft_strncmp(line, "rrr", 3) == 0)
			reverse_rotate2(&a, &b);
		else
			ft_printf("Error\n");
		free(line);
	}

	return (0);
	//Read in similar values as for push swap using same methods!
	//Check the inputs similar to the push_swap
	//Read in the stack operations from push_swap or directly typed in console with get_next_line stdin = 0;
	//execute on the read operations
	//check if the list has been sorted properly
}
