/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:34:22 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/14 21:26:12 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], t_list *a)
{
	if (parse_input(argc, argv, a) == -1)
	{
// check with gnl		ft_printf("Error\n");
		free_list(a);
	}

	else if (check_issorted(a) == 1)
	{
		ft_printf("\n");
		free_list(a);
		return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	a;
	t_list	b;

	ft_list_init(&a);
	ft_list_init(&b);
	parse_input(argc, argv, &a);
	char	*line;

	line = "s";
	while (line != NULL)
	{
		line = get_next_line(0);
  		if (ft_strncmp(line, "sa", 2) == 0)
			swap(&a);
		else if (ft_strncmp(line, "sb", 2) == 0)
			swap(&b);
		else if (ft_strncmp(line, "ss", 2) == 0)
		{
			swap(&a);
			swap(&b);
		}
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
	print_stacks(&a, &b);

	return (0);
	//Read in similar values as for push swap using same methods!
	//Check the inputs similar to the push_swap
	//Read in the stack operations from push_swap or directly typed in console with get_next_line stdin = 0;
	//execute on the read operations
	//check if the list has been sorted properly
}
