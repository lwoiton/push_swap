/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calculation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:17:26 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:17:51 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcRotations(t_list *A, t_list *B)
{
	t_node	*curr_B;
	int		nextRank;
	int		rotations;

	curr_B = B->head;
	rotations = 0;
	resetRotations(B);
	while (rotations < B->size)
	{
		curr_B->rb = rotations;
		curr_B = curr_B->next;
		if (curr_B->rank < A->minRank)
			curr_B->ra = getRotations_A(A, A->minRank);
		else
		{
			nextRank = getNextRank(A, curr_B->rank);
			curr_B->ra = getRotations_A(A, nextRank);
		}
		rotations++;
	}
	setRotationDirection(A, B);
	return (0);
}

int	getRotations_A(t_list *A, int nextRank)
{
	int		rotations;
	t_node	*curr_A;

	rotations = 0;
	curr_A = A->head;
	while (curr_A->rank != nextRank)
	{
		curr_A = curr_A->next;
		rotations++;
	}
	return (rotations);
}

int	resetRotations(t_list *B)
{
	t_node	*curr_B;
	int		iter;

	curr_B = B->head;
	iter = 0;
	while (iter++ < B->size)
	{
		curr_B->rb = 0;
		curr_B->rrb = 0;
		curr_B->ra = 0;
		curr_B->rra = 0;
		curr_B = curr_B->next;
	}
	return (0);
}

int	setRotationDirection(t_list *A, t_list *B)
{
	t_node	*curr_B;
	int		iter;

	curr_B = B->head;
	iter = 0;
	while (iter++ < B->size)
	{
		if (curr_B->rb > B->size / 2)
		{
			curr_B->rrb = B->size - curr_B->rb;
			curr_B->rb = 0;
		}
		if (curr_B->ra > A->size / 2)
		{
			curr_B->rra = A->size - curr_B->ra;
			curr_B->ra = 0;
		}
		curr_B = curr_B->next;
	}
	return (0);
}
