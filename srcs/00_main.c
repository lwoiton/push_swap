/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 06:22:04 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_builder(t_list *a)
{
	t_list	b;
	t_node	*sel_node;

	ft_list_init(&b);
	analyse_ranks(a);
	partition(a, &b);
	sort_three(a);
	while (a->size > 0)
	{
		calc_rotations(a, &b);
		calc_costs(a, &b);
		sel_node = find_min_cost(&b);
		execute(a, &b, sel_node);
	}
	while (a->head->rank != 0 || a->head->prev->rank != a->max_rank)
	{
		rotate1(a);
		ft_printf("ra\n");
	}
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

int	partition(t_list *a, t_list *b)
{
	int		chunk_size;
	int		upper_curr_chunk;
	int		lower_curr_chunk;
	int		upper_chunk_counter;
	int		lower_chunk_counter;

	chunk_size = (a->size + CHUNK_NR - 1) / CHUNK_NR;
	upper_curr_chunk = 0;
	lower_curr_chunk = 1;
	upper_chunk_counter = 0;
	lower_chunk_counter = 0;
	while (a->size > 3)
	{
		if (a->head->rank / chunk_size == upper_curr_chunk && \
				a->head->rank < (a->size + b->size) - 3)
		{
			push(b, a);
			ft_printf("pb\n");
			upper_chunk_counter++;
		}
		else if (a->head->rank / chunk_size == lower_curr_chunk && \
				a->head->rank < (a->size + b->size) - 3)
		{
			push(b, a);
			ft_printf("pb\n");
			if (a->head->next->rank / chunk_size > lower_curr_chunk\
			&& a->head->next->rank >= (a->size + b->size) - 3)
			{
				rotate2(a, b);
				ft_printf("rr\n");	
			}
			else
			{
				rotate1(b);
				ft_printf("rb\n");
			}
			lower_chunk_counter++;
		}
		else
		{
			a->head = a->head->next;
			ft_printf("ra\n");
		}
		if (upper_chunk_counter == chunk_size)
		{
			upper_chunk_counter = 0;
			upper_curr_chunk += 2;
		}
		else if (lower_chunk_counter == chunk_size)
		{
			lower_chunk_counter = 0;
			lower_curr_chunk += 2;
		}
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_list	a;

	ft_list_init(&a);
	parse_input(argc, argv, &a);
	//analyseRanks(t_list *a);
	chunk_builder(&a);
    	return (0);
}
