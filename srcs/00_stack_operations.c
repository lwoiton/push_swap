/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:10:27 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:10:41 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *list)
{
	list->head->prev->next = list->head->next;
	list->head->next->prev = list->head->prev;
	list->head->prev = list->head->next;
	list->head->next = list->head->next->next;
	list->head->prev->next = list->head;
	list->head->next->prev = list->head;
	list->head = list->head->prev;
	return (0);
}

int	push(t_list *dst, t_list *src)
{
	if (src->size == 0)
		return (-1);
	if (dst->head == NULL )
	{
		dst->head = src->head;
		src->head->next->prev = src->head->prev;
		src->head->prev->next = src->head->next;
		src->head = src->head->next;
		dst->head->next = dst->head;
		dst->head->prev = dst->head;
	}
	else
	{
		src->head->next->prev = src->head->prev;
		src->head->prev->next = src->head->next;
		dst->head->prev->next = src->head;
		src->head->prev = dst->head->prev;
		dst->head->prev = src->head;
		src->head = src->head->next;
		dst->head->prev->next = dst->head;
		dst->head = dst->head->prev;
	}
	dst->size += 1;
	src->size -= 1;
	return (0);
}
