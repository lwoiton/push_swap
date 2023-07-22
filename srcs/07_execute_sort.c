/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:51:30 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:51:42 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	executeDoubleRotation(t_list *A, t_list *B, t_node *sel_node)
{
	while (sel_node->ra > 0 && sel_node->rb > 0)
	{
		rotate2(A, B);
		ft_printf("rr\n");
		sel_node->ra--;
		sel_node->rb--;
	}
	while (sel_node->rra > 0 && sel_node->rrb > 0)
	{
		reverse_rotate2(A, B);
		ft_printf("rrr\n");
		sel_node->rra--;
		sel_node->rrb--;
	}
}

void	executeRotation_A(t_list *A, t_node *sel_node)
{
	while (sel_node->ra > 0)
	{
		rotate1(A);
		ft_printf("ra\n");
		sel_node->ra--;
	}
	while (sel_node->rra > 0)
	{
		reverse_rotate1(A);
		ft_printf("rra\n");
		sel_node->rra--;
	}
}

void	executeRotation_B(t_list *B, t_node *sel_node)
{
	while (sel_node->rb > 0)
	{
		rotate1(B);
		ft_printf("rb\n");
		sel_node->rb--;
	}
	while (sel_node->rrb > 0)
	{
		reverse_rotate1(B);
		ft_printf("rrb\n");
		sel_node->rrb--;
	}
}

int	execute(t_list *A, t_list *B, t_node *sel_node)
{
	executeDoubleRotation(A, B, sel_node);
	executeRotation_A(A, sel_node);
	executeRotation_B(B, sel_node);
	push(A, B);
	ft_printf("pa\n");
	A->maxRank = getMaxRank(A);
	A->minRank = getMinRank(A);
	return (0);
}
