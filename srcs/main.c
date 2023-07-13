/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/12 17:28:20 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_builder(t_list *A)
{
	t_list	B;
	int	*sorted_A;
	int	i;
	int	j;
	t_node	*tmp;
	
	ft_list_init(&B);
	sorted_A = (int*)malloc(A->size * sizeof(int));
	i = 0;
	tmp = A->head;
	while(i < A->size)
	{
		sorted_A[i] = tmp->content;
		tmp = tmp->next;
		++i;
	}
	ft_sort_int_tab(sorted_A, A->size);
	displayList(A);
	//Build indexes in the linked list in another while loop
	
	i = 0;
	tmp = A->head;
	while (i <= A->size)
	{
		j = 0;
		while (j <= A->size)
		{
			if (sorted_A[j] == tmp->content)
				tmp->rank = j;
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = A->head;
	while (tmp->next != A->head)
	{
		ft_printf("%d(%d,%d) ",tmp->content, tmp->rank, tmp->rank/2);
		tmp = tmp ->next;
	}
	if (tmp->next == A->head)
		ft_printf("%d(%d,%d) ",tmp->content, tmp->rank, tmp->rank/2);
	i = 0;
	while (i < A->size)
	{
		push(&B, A);
		i++;
	}
	displayList(A);
	displayList(&B);
}

int	rotate_single(t_list *list)
{
	list->head = list->head->next;
	return (0);
}

int	rotate_both(t_list *list_a, t_list *list_b)
{
	list_a->head = list_a->head->next;
	list_b->head = list_b->head->next;
	return (0);
}

int	reverse_rotate_single(t_list *list)
{
	list->head = list->head->prev;
	return (0);
}

int	reverse_rotate_both(t_list *list_a, t_list *list_b)
{
	list_a->head = list_a->head->prev;
	list_b->head = list_b->head->prev;
	return (0);
}

int	swap(t_list *list)
{
	int	tmp_val;
	int	tmp_rank;
	
	tmp_val = list->head->content;
	list->head->content = list->head->next->content;
	list->head->next->content = tmp_val;
	
	tmp_rank = list->head->rank;
	list->head->rank = list->head->next->rank;
	list->head->next->rank = tmp_rank;
	return (0);
}

int	push(t_list *dst, t_list *src)
{
	if (dst->head == NULL)
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
		dst->head->next->prev = src->head;
		dst->head->prev->next = src->head;
		dst->head = src->head;
		src->head->next->prev = src->head->prev;
		src->head->prev->next = src->head->next;
		src->head = src->head->next;
	}
	return (0);
}

t_node	 *ft_lstnew(int	content)
{
    t_node *newNode;
    
    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
    	return (NULL);
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
        ft_printf("%d(%d) ", currentNode->content, currentNode->rank);
        currentNode = currentNode->next;
    }
    ft_printf("%d(%d) ", currentNode->content, currentNode->rank);
    ft_printf("\nSize: %d\n", list->size);
}

int main(int argc, char* argv[])
{	
	t_list list;
	char	**parsed_params;
	int	i;

	ft_list_init(&list);
	if (argc < 2) {
        	ft_printf("No input string provided.\n");
        	return 1;
	}
	else if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		i = 0;
		parsed_params = ft_split(argv[1], ' ');
		while (parsed_params[i] != NULL)
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(parsed_params[i])));
			++i;
		}	
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	}
	else
	{
	
	}
	chunk_builder(&list);
    	return 0;
}
