/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_ranks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:42:45 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:43:06 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyseRanks(t_list *A)
{
	t_node	*curr_A;
	int	*sorted_A;
	int	iter;
	
	curr_A = A->head;
	sorted_A = (int*)malloc(A->size * sizeof(int));
	iter = 0;
	while(i < A->size)
	{
		sorted_A[iter] = curr_A->content;
		curr_A = curr_A->next;
		iter++;
	}
	ft_sort_int_tab(sorted_A, A->size);
	assignRanks(t_list *A, int *sorted_A);
	free(sorted_A);
}

void	ft_sort_int_tab(int *tab, int size)
{	
	int	i;
	int	cur;
	int	buff;

	i = 0;
	while (i < size - 1)
	{	
		cur = i + 1;
		while (cur < size)
		{
			if (tab[i] > tab[cur])
			{
				buff = tab[cur];
				tab[cur] = tab[i];
				tab[i] = buff;
			}
			++cur;
		}
		++i;
	}
}

void	assignRanks(t_list *A, int *sorted_A)
{
	t_node	*curr_A;
	int	iter;
	int	rank;
	
	curr_A = A->head;
	iter = 0;
	while (iter++ < A->size)
	{
		rank = 0;
		while (rank < A->size)
		{
			if (sorted_A[rank] == curr_A->content)
			{
				curr_A->rank = rank;
				break;
			}
			rank++;
		}
		curr_A = curr_A->next;
	}
}
