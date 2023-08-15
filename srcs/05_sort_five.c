/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:47:07 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/15 13:49:31 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two_elements_to_b(t_list *a, t_list *b)
{
	while (a->size > 3)
	{
		if (a->head->rank == a->min_rank || \
				(a->head->rank == a->min_rank + 1 \
				&& a->head->rank != 3) || \
				a->head->rank == a->size + b->size)
			push(b, a);
		else if (a->head->prev->rank == a->min_rank || \
				(a->head->prev->rank == a->min_rank + 1 && \
				a->head->prev->rank != 3) || \
				a->head->prev->rank == a->size + b->size)
			reverse_rotate1(a);
		else
			rotate1(a);
	}
}

int	sort_three(t_list *a)
{
	if (a->head->content > a->head->next->content && \
			a->head->content > a->head->next->next->content)
		rotate1(a);
	else if (a->head->next->content > a->head->content && \
			a->head->next->content > a->head->next->next->content)
		reverse_rotate1(a);
	if (a->head->content > a->head->next->content)
		swap(a);
	a->max_rank = a->head->prev->rank;
	a->min_rank = a->head->rank;
	return (0);
}

int	sort_five(t_list *a, t_list *b)
{
	push_two_elements_to_b(a, b);
	sort_three(a);
	while (a->size < 5)
	{
		if (b->head->rank > a->max_rank)
		{
			push(a, b);
			rotate1(a);
		}
		else
		{
			push(a, b);
			if (a->head->rank > a->head->next->rank)
				swap(a);
		}
	}
	return (0);
}

/* void	presort(t_list *a, t_list *b)
{
	if (a->size <= 5)
		sort_five(a, b);
	else
	{
		divide_into_chunks(a, b);
		sort_three(a);
	}
	return ;
} */