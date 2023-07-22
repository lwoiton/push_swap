/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:15:17 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:15:34 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcCosts(t_list *A, t_list *B)
{
	t_node	*curr_B;
	int		iter;

	curr_B = B->head;
	iter = 0;
	while (iter++ < B->size)
	{
		if (curr_B->ra > 0 && curr_B->rb > 0)
			curr_B->cost = max(curr_B->ra, curr_B->rb);
		else if (curr_B->rra > 0 && curr_B->rrb > 0)
			curr_B->cost = max(curr_B->rra, curr_B->rrb);	
		else
			curr_B->cost = curr_B->ra + curr_B->rb + curr_B->rrb + curr_B->rra;
		accountChunkCost(A, B, curr_B);
		//accountAdjacency(A, curr_B);
		curr_B = curr_B->next;
	}
	return (0);
}

int	accountAdjacency(t_list *A, t_node *curr_B)
{
	t_node	*curr_A;
	int		steps;
	int		diff;

	curr_A = A->head;
	if (curr_B->ra)
		steps = curr_B->ra;
	else
		steps = curr_B->rra;
	while (steps-- > 0)
		curr_A = curr_A->next;
	diff = curr_A->rank - curr_B->rank;
	curr_B->cost += diff;
	return (0);
}

int	accountChunkCost(t_list *A, t_list *B, t_node *curr_B)
{
	int	chunk_size;

	chunk_size = ((A->size + B->size) + CHUNK_NR - 1) / CHUNK_NR;
	if (curr_B->rank / chunk_size != A->head->rank / chunk_size)
		curr_B->cost += NOT_IN_CHUNK_PANELTY;
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
