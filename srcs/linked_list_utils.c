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

t_node	 *ft_lstnew(int	content)
{
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->content = content;
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
	{	temp = list->head;
		while (temp->next != list->head)
		{	
			if (temp->content == node->content) 
			{	free(node);
				return (-1);
			}
			temp = temp->next;
		}
		if (temp->content == node->content)
		{       free(node);
			return (-1);
		}
        	node->next = list->head;
		list->head->prev = node;
        	node->prev = temp;
		temp->next = node;

	}
	return (0);
}

void ft_list_init(t_list *list)
{
	list->size = 0;
	list->head = NULL;
}

void displayList(t_list *list)
{
    t_node *currentNode = list->head;

    if (currentNode == NULL)
    {
        ft_printf("List is empty.\n");
        return;
    }

    ft_printf("Linked List: ");
    while (currentNode->next != list->head)
    {
        ft_printf("%d ", currentNode->content);
        currentNode = currentNode->next;
    }
    ft_printf("%d ", currentNode->content);
    ft_printf("\nSize: %d\n", list->size);
}
