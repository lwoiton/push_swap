/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 03:09:25 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 03:09:45 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate1(t_list *list)
{
	list->head = list->head->next;
	return (0);
}

int	rotate2(t_list *A, t_list *B)
{
	A->head = A->head->next;
	B->head = B->head->next;
	return (0);
}

int	reverse_rotate1(t_list *list)
{
	list->head = list->head->prev;
	return (0);
}

int	reverse_rotate2(t_list *A, t_list *B)
{
	A->head = A->head->prev;
	B->head = B->head->prev;
	return (0);
}

