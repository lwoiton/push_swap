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

void	display_list(t_list *list)
{
	t_node	*curr_n;
	int		chunk_size;

	curr_n = list->head;
	chunk_size = (list->size + CHUNK_NR - 1) / CHUNK_NR;
	if (curr_n == NULL)
	{
		ft_printf("List is empty.\n");
		return ;
	}
	ft_printf("Linked List: ");
	while (curr_n->next != list->head)
	{
		ft_printf("%d(%d,%d) ", curr_n->content, \
			curr_n->rank, curr_n->rank / chunk_size);
		curr_n = curr_n->next;
	}
	ft_printf("%d(%d,%d)\n", curr_n->content, \
		curr_n->rank, curr_n->rank / chunk_size);
	ft_printf("\nSize: %d\n", list->size);
}

void	print_stacks_head(void)
{
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
	ft_printf("| Stack A | rank | chunk | cost | ra | rb | rra | rrb |\
	   | Stack B | rank | chunk | cost | ra | rb | rra | rrb |\n");
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
}

void	print_stack_a(t_node *ca, int cs, int size_a)
{
	if (size_a)
	{
		ft_printf("|%9d|%6d|%7d|%6d|%4d|%4d|%5d|%5d|   ", \
			ca->content, ca->rank, ca->rank / cs, ca->cost, \
			ca->ra, ca->rb, ca->rra, ca->rrb);
		ca = ca->next;
		size_a--;
	}
	else
	{
		ft_printf("|%9s|%6s|%7s|%6s|%4s|%4s|%5s|%5s|   ", \
			"-", "-", "-", "-", "-", "-", "-", "-");
	}
}

void	print_stack_b(t_node *cb, int cs, int size_b)
{	
	if (size_b)
	{	
		ft_printf("|%9d|%6d|%7d|%6d|%4d|%4d|%5d|%5d|\n", \
		cb->content, cb->rank, cb->rank / cs, cb->cost, \
		cb->ra, cb->rb, cb->rra, cb->rrb);
		cb = cb->next;
		size_b--;
	}
	else
	{
		ft_printf("|%9s|%6s|%7s|%6s|%4s|%4s|%5s|%5s|\n", \
			"-", "-", "-", "-", "-", "-", "-", "-");
	}
	ft_printf("+---------+------+-------+------+----+----+-----+-----+\
	   +---------+------+-------+------+----+----+-----+-----+\n");
}

void	print_stacks(t_list *a, t_list *b)
{
	t_node	*ca;
	t_node	*cb;
	int		cs;
	int		size_a;
	int		size_b;

	ca = a->head;
	cb = b->head;
	cs = ((a->size + b->size) + CHUNK_NR - 1) / CHUNK_NR;
	size_a = a->size;
	size_b = b->size;
	if (ca == NULL || cb == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	print_stacks_head();
	while (size_b || size_a)
	{
		print_stack_a(ca, cs, size_a);
		print_stack_b(cb, cs, size_b);
	}
}