/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/10 14:28:16 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_builder(t_list *a)
{
	t_list	b;
	t_node	*sel_node;

	ft_list_init(&b);
	partition(a, &b);
	sort_three(a);
	while (b.size > 0)
	{
		calc_rotations(a, &b);
		calc_costs(a, &b);
		sel_node = find_min_cost(&b);
		execute(a, &b, sel_node);
	}
}

int	final_rotation(t_list *a)
{
	while (a->head->rank != 0 || a->head->prev->rank != a->max_rank)
	{
		if (a->head->rank > a->max_rank / 2)
		{
			rotate1(a);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rotate1(a);
			ft_printf("rra\n");
		}
	}
	return (0);
}

t_node	*find_min_cost(t_list *b)
{
	t_node	*curr_b;
	t_node	*best_to_move;
	int		min_cost;
	int		inter;

	curr_b = b->head;
	min_cost = curr_b->cost;
	inter = 0;
	while (inter++ < b->size)
	{
		if (curr_b->cost < min_cost)
		{
			min_cost = curr_b->cost;
			best_to_move = curr_b;
		}
		curr_b = curr_b->next;
	}
	return (best_to_move);
}

int	sort_three(t_list *a)
{
	if (a->head->content > a->head->next->content && \
			a->head->content > a->head->next->next->content)
	{
		rotate1(a);
		ft_printf("ra\n");
	}
	else if (a->head->next->content > a->head->content && \
			a->head->next->content > a->head->next->next->content)
	{
		reverse_rotate1(a);
		ft_printf("rra\n");
	}
	if (a->head->content > a->head->next->content)
	{
		swap(a);
		ft_printf("sa\n");
	}
	a->max_rank = a->head->prev->rank;
	a->min_rank = a->head->rank;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	a;

	ft_list_init(&a);
	parse_input(argc, argv, &a);
	analyse_ranks(&a);
	chunk_builder(&a);
	final_rotation(&a);
	return (0);
}
