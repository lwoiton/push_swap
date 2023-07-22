/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 02:03:16 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_builder(t_list *A)
{
	t_list	B;
	t_node	*sel_node;
	
	ft_list_init(&B);
	analyseRanks(A);
	partition(A, &B);
	sortThree(A);
	while (B.size > 0)
	{
		calcRotations(A, &B);
		calcCosts(A, &B);
		sel_node = findMinCost(&B);
		execute(A, &B, sel_node);
	}
	while (A->head->rank != 0 || A->head->prev->rank != A->maxRank)
	{
		rotate1(A);
		ft_printf("ra\n");
	}
}

t_node	*findMinCost(t_list *B)
{
	t_node	*curr_B;
	t_node	*bestToMove;
	int		minCost;
	int		inter;

	curr_B = B->head;
	minCost = curr_B->cost;
	inter = 0;
	while (inter++ < B->size)
	{
		if (curr_B->cost < minCost )
		{
			minCost = curr_B->cost;
			bestToMove = curr_B;
		}
		curr_B = curr_B->next;
	}
	return (bestToMove);
}

int	sortThree(t_list *A)
{
	if (A->head->content > A->head->next->content && \
			A->head->content > A->head->next->next->content)
	{
		rotate1(A);
		ft_printf("ra\n");
	}
	else if (A->head->next->content > A->head->content && \
			A->head->next->content > A->head->next->next->content)
	{
		reverse_rotate1(A);
		ft_printf("rra\n");
	}
	if (A->head->content > A->head->next->content)
	{
		swap(A);
		ft_printf("sa\n");
	}
	A->maxRank = A->head->prev->rank;
	A->minRank = A->head->rank;
	return (0);
}

int	partition(t_list *A, t_list *B)
{
	int		chunk_size;
	int		upper_curr_chunk;
	int		lower_curr_chunk;
	int		upper_chunk_counter;
	int		lower_chunk_counter;

	chunk_size = (A->size + CHUNK_NR - 1) / CHUNK_NR;
	upper_curr_chunk = 0;
	lower_curr_chunk = 1;
	upper_chunk_counter = 0;
	lower_chunk_counter = 0;
	while (A->size > 3)
	{
		if (A->head->rank / chunk_size == upper_curr_chunk &&\
				A->head->rank < (A->size + B->size) - 3)
		{
			push(B, A);
			ft_printf("pb\n");
			upper_chunk_counter++;
		}
		else if(A->head->rank / chunk_size == lower_curr_chunk &&\
				A->head->rank < (A->size + B->size) - 3)
		{
			push(B, A);
			ft_printf("pb\n");
			if (A->head->next->rank / chunk_size > lower_curr_chunk &&\
					A->head->next->rank >= (A->size + B->size) - 3)
			{
				rotate2(A, B);
				ft_printf("rr\n");	
			}
			else
			{
				rotate1(B);
				ft_printf("rb\n");
			}
			lower_chunk_counter++;
		}
		else
		{
			A->head = A->head->next;
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
	t_list	*A;
	
	A = parseInput(argc, argv);
	//analyseRanks(t_list *A);
	chunk_builder(A);
    	return (0);
}
