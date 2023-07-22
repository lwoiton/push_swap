/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ranks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:14:02 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:14:16 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getMinRank(t_list *A)
{
	t_node	*curr_A;
	int		minRank;
	int		iter;

	curr_A = A->head;
	minRank = curr_A->rank;
	iter = 0;
	while (iter++ < A->size)
	{
		if(curr_A->rank < minRank)
			minRank = curr_A->rank;
		curr_A = curr_A->next;
	}
	return (minRank);
}

int	getMaxRank(t_list *A)
{
	t_node	*curr_A;
	int		maxRank;
	int		iter;
	
	curr_A = A->head;
	maxRank = -1;
	iter = 0;
	while (iter++ < A->size)
	{
		if (curr_A->rank > maxRank)
			maxRank = curr_A->rank;
		curr_A = curr_A->next;
	}
	return (maxRank);
}

int	getNextRank(t_list *A, int currRank_BN)
{
	t_node	*curr_A;
	int		nextRank;
	int		iter;

	curr_A = A->head;
	nextRank = A->maxRank;
	iter = 0;
	while (iter < A->size)
	{
		if (curr_A->rank > currRank_BN && curr_A->rank < nextRank)
			nextRank = curr_A->rank;
		curr_A = curr_A->next;
		iter++;
	}
	return (nextRank);
}
