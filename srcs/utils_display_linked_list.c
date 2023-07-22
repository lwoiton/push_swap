/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:57:38 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 02:57:40 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void displayList(t_list *list)
{
    t_node 	*curr_N = list->head;
	int		chunk_size;

	chunk_size = (list->size + CHUNK_NR - 1) / CHUNK_NR;
    if (curr_N == NULL)
    {
        ft_printf("List is empty.\n");
        return;
    }
    ft_printf("Linked List: ");
    while (curr_N->next != list->head)
    {
	ft_printf("%d(%d,%d) ",curr_N->content, /
	curr_N->rank, curr_N->rank/chunk_size);
        curr_N = curr_N->next;
    }
	ft_printf("%d(%d,%d)\n",curr_N->content, /
	curr_N->rank, curr_N->rank/chunk_size);
    ft_printf("\nSize: %d\n", list->size);
}

void	printStacksHead()
{
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
	ft_printf("| Stack A | rank | chunk | cost | ra | rb | rra | rrb |\
	   | Stack B | rank | chunk | cost | ra | rb | rra | rrb |\n");
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
}

void	printStackA(t_node *cA, int cs, int sizeA)
{
	if (sizeA)
	{
		ft_printf("|%9d|%6d|%7d|%6d|%4d|%4d|%5d|%5d|   ", \
		cA->content, cA->rank, cA->rank / cs, cA->cost, \
		cA->ra, cA->rb, cA->rra, cA->rrb);
		cA = cA->next;
		sizeA--;
	}
	else
	{
		ft_printf("|%9s|%6s|%7s|%6s|%4s|%4s|%5s|%5s|   ",\
		 "-", "-", "-", "-", "-", "-", "-", "-");
	}
}

void	printStackA(t_node *cA, int cs, int sizeA)
{	
	if (sizeB)
	{	
		ft_printf("|%9d|%6d|%7d|%6d|%4d|%4d|%5d|%5d|\n", \
		cB->content, cB->rank, cB->rank / cs, cB->cost, \
		cB->ra, cB->rb, cB->rra, cB->rrb);
		cB = cB->next;
		sizeB--;
	}
	else
	{
		ft_printf("|%9s|%6s|%7s|%6s|%4s|%4s|%5s|%5s|\n",\
		 "-", "-", "-", "-", "-", "-", "-", "-");
	}
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
}

void printStacks(t_list *A, t_list *B)
{
	t_node	*cA;
	t_node	*cB;
	int		cs;
	
	int		sizeA;
	int		sizeB;
	cA = A->head;
	cB = B->head;
	cs = ((A->size + B->size) + CHUNK_NR - 1) / CHUNK_NR;
	sizeA = A->size;
	sizeB = B->size;
	if (cA == NULL || cB == NULL)
	{
		ft_printf("Error\n");
		return;
	}
	printStacksHead();
	while (sizeB || sizeA)
	{
		printStackA(cA, cs, sizeA);
		printStackB(cB, cs, sizeB);
	}
}
