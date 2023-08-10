/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:01:25 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/10 14:27:00 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_init(t_list *list)
{
	list->size = 0;
	list->chunk_nr = 0;
	list->chunk_size = 0;
	list->min_rank = INT_MAX;
	list->max_rank = INT_MIN;
	list->head = NULL;
}

int	determine_chunknr(t_list *a)
{
	if (a->size > 5 && a->size <= 20)
		a->chunk_nr = 2; 
	else if (a->size > 20 && a->size <= 50)
		a->chunk_nr = 3;
	else if (a->size > 50 && a->size <= 100)
		a->chunk_nr = 4;
	else if (a->size > 100 && a->size <= 200)
		a->chunk_nr = 5;
	else if (a->size > 200 && a->size <= 400)
		a->chunk_nr = 7;
	else if (a->size > 400)
		a->chunk_nr = 8;
	a->chunk_size = (a->size + a->chunk_nr - 1) / a->chunk_nr;
	return (0);
}

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->rank = 0;
	new->cost = 0;
	new->ra = 0;
	new->rb = 0;
	new->rra = 0;
	new->rrb = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_lstadd_back(t_list *list, t_node *node)
{
	t_node	*temp;

	list->size += 1;
	if (list->head == NULL)
	{
		list->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		temp = list->head;
		while (temp->next != list->head)
		{
			temp = temp->next;
		}
		node->next = list->head;
		list->head->prev = node;
		node->prev = temp;
		temp->next = node;
	}
	return (0);
}
