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

t_node	 *ft_lstnew(void *content)
{
    t_node *newNode = (t_node *)malloc(sizeof(t_node));
    newNode->content = content;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void ft_lstadd_back(t_list *list, t_node *node)
{
	list->size += 1;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}

void ft_list_init(t_list *list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

void displayList(t_list *list)
{
    t_node *currentNode = list->head;

    if (currentNode == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (currentNode != NULL)
    {
        printf("%d ", *(int*)currentNode->content);
        currentNode = currentNode->next;
    }
    printf("\nSize: %d\n", list->size);
}
