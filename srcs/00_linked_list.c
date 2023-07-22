/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:01:25 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/10 19:01:27 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_list_init(t_list *list)
{
	list->size = 0;
	list->minRank = INT_MAX;
	list->maxRank = INT_MIN;
	list->head = NULL;
}

t_node	*ft_lstnew(int	content)
{
    t_node *newNode;
    
    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
    	return (NULL);
    newNode->content = content;
	newNode->rank = 0;
	newNode->cost = 0;
	newNode->ra = 0;
	newNode->rb = 0;
	newNode->rra = 0;
	newNode->rrb = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
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
