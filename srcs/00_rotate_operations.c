/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:09:25 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/08 14:52:50 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate1(t_list *list)
{
	list->head = list->head->next;
	return (0);
}

int	rotate2(t_list *a, t_list *b)
{
	a->head = a->head->next;
	b->head = b->head->next;
	return (0);
}

int	reverse_rotate1(t_list *list)
{
	list->head = list->head->prev;
	return (0);
}

int	reverse_rotate2(t_list *a, t_list *b)
{
	a->head = a->head->prev;
	b->head = b->head->prev;
	return (0);
}
