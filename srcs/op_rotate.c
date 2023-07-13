/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:23:13 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/13 14:41:45 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rotate_single(t_list *list)
{
	list->head = list->head->next;
	return (0);
}

int rotate_both(t_list *list_a, t_list *list_b)
{
	list_a->head = list_a->head->next;
	list_b->head = node_b->head->next;
	return (0);
}

int	reverse_rotate_single(t_list *list)
{
	list->head = list->head->prev;
	return (0);
}

int reverse_rotate_both(t_list *list_a, t_list *list_b)
{
	list_a->head = list_a->head->prev;
	list_b->head = list_b->head->prev;
	return (0);
}


