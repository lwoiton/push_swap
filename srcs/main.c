/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/21 12:02:50 by luca             ###   ########.fr       */
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

	//Build indexes in the linked list in another while loop	
	i = 0;
	tmp = A->head;
	while (tmp->next != A->head)
	{
		j = 0;
		while (j < A->size)
		{
			if (sorted_A[j] == tmp->content)
			{
				tmp->rank = j;
				break;
			}
			j++;
		}
		tmp = tmp->next;
	}
	if (tmp->next == A->head)
	{
		j = 0;
		while (j < A->size)
		{
			if (sorted_A[j] == tmp->content)
			{
				tmp->rank = j;
				break;
			}
			j++;
		}
	}
	partition(A, &B);
	sort_three(A);
	while (B->size > 0)
	{
		calculate_rotations(A, B);
		calculate_costs(B);
		selected_node = find_min_cost(B);
		execute(A, B, selected_node);
	}
}

int	execute(t_list *A, t_list *B, t_node *sel_node)
{
	while (sel_node->ra > 0 && sel_node->rb > 0)
	{
		rotate2(A, B);
		ft_printf("rr\n");
		sel_node->ra--;
		sel_node->rb--;
	}
	while (sel_node->rra > 0 && sel_node->rrb > 0)
	{
		rotate2(A, B);
		ft_printf("rrr\n");
		sel_node->rra--;
		sel_node->rrb--;
	}
	while (sel_node->rb > 0)
	{
		rotate1(B);
		ft_printf("rb\n");
		sel_node->rb--;
	}
	while (sel_node->rrb > 0)
	{
		rotate1(B);
		ft_printf("rrb\n");
		sel_node->rrb--;
	}
	push(A,B);
	ft_printf("pa\n");
	while (sel_node->ra > 0)
	{
		rotate1(A);
		ft_printf("ra\n");
		sel_node->ra--;
	}
	while (sel_node->rra > 0)
	{
		rotate1(A);
		ft_printf("rra\n");
		sel_node->rra--;
	}
	return (0);
}

t_node	*find_min_cost(t_list *B)
{
	t_node	*B_tmp;
	t_node	*adress_min_cost;
	int		min_cost;

	B_tmp = B->head;
	min_cost = B_tmp->cost;
	while (B_tmp->next != B->head)
	{
		if (B_tmp->cost < min_cost)
		{
			min_cost = B_tmp->cost;
			adress_min_cost = B_tmp;
		}
		B_tmp = B_tmp->next;
	}
	return (adress_min_cost);
}

int	calculate_costs(t_list *B)
{
	t_node *B_tmp;

	B_tmp = B->head;
	while (B_tmp->next != B->head)
	{
		if (B_tmp->ra > 0 && B_tmp->rb > 0)
			B_tmp->costs = max(B_tmp->ra, B_tmp->rb);
		else if (B_tmp->rra > 0 && B_tmp->rrb > 0)
			B_tmp->costs = max(B_tmp->rra, B_tmp->rrb);	
		else
			B_tmp->costs = B_tmp->ra + B_tmp->rb + B_tmp->rrb + B_tmp->rra;
		B_tmp = B_tmp->next;
	}
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	sort_three(t_list *A)
{
	if (A->head->content > A->head->next->content && \
			A->head->content > A->head->next->next->content)
	{
		rotate1(A);
		ft_printf("ra\n");
	}
	else if (A->head->next->content > A->head->content && \
			A->head->next->content > A->head->next->next->content)
	{
		reverse_rotate1(A);
		ft_printf("rra\n");
	}
	if (A->head->content > A->head->next->content)
	{
		swap(A);
		ft_printf("sa\n");
	}
	return (0);
}

int	calculate_rotations(t_list *A, t_list *B)
{
	t_node	*B_tmp;
	int		count;

	B_tmp = B->head;
	count = 0;
	while (B_tmp->next != B->head)
	{
		if (count > B->size / 2)
		{
			B_tmp->rrb = B->size - count;
			B_tmp->rb = 0;
		}
		else
		{
			B_tmp->rb = count;
			B_tmp->rrb = 0;
		}
		find_position_in_a(A, B_tmp);
		B_tmp = B_tmp->next;
		cout++;
	}
	return (0);	
}

int	find_position_in_a(t_list *A, t_node *curr_B)
{
	t_node	*A_tmp;
	int		count;

	A_tmp = A->head;
	count = 0;
	while (A_tmp->next != A->head)
	{
		if (A_tmp->next->rank > curr_B->rank && curr_B->rank > A_tmp->prev->rank)
			break;
		count++;
		A_tmp = A_tmp->next;
	}
	if (count > A->size / 2)
	{
		curr_B->ra = 0;
		curr_B->rra = A->size - count;
	}
	else
	{
		curr_B->ra = count;
		curr_B->rra = 0;
	}
	return (0);
}

int	partition(t_list *A, t_list *B)
{
	int		chunk_size;
	int		upper_curr_chunk;
	int		lower_curr_chunk;
	int		upper_chunk_counter;
	int		lower_chunk_counter;

	chunk_size = (A->size + CHUNK_NR - 1) / CHUNK_NR;
	upper_curr_chunk = 0;
	lower_curr_chunk = 1;
	upper_chunk_counter = 0;
	lower_chunk_counter = 0;
	while (A->size > 3)
	{
		if (A->head->rank / chunk_size == upper_curr_chunk &&\
				A->head->rank < (A->size + B->size) - 3)
		{
			push(B, A);
			ft_printf("pb\n");
			upper_chunk_counter++;
		}
		else if(A->head->rank / chunk_size == lower_curr_chunk &&\
				A->head->rank < (A->size + B->size) - 3)
		{
			push(B, A);
			ft_printf("pb\n");
			rotate1(B);
			ft_printf("rb\n");
			lower_chunk_counter++;
		}
		else
		{
			A->head = A->head->next;
			ft_printf("ra\n");
		}
		if (upper_chunk_counter == chunk_size)
		{
			upper_chunk_counter = 0;
			upper_curr_chunk += 2;
		}
		else if (lower_chunk_counter == chunk_size)
		{
			lower_chunk_counter = 0;
			lower_curr_chunk += 2;
		}
	}
	return (0);
}

int	rotate1(t_list *list)
{
	list->head = list->head->next;
	return (0);
}

int	rotate2(t_list *list_A, t_list *list_B)
{
	list_A->head = list_A->head->next;
	list_B->head = list_B->head->next;
	return (0);
}

int	reverse_rotate1(t_list *list)
{
	list->head = list->head->prev;
	return (0);
}

int	reverse_rotate2(t_list *list_A, t_list *list_B)
{
	list_A->head = list_A->head->prev;
	list_B->head = list_B->head->prev;
	return (0);
}

int swap(t_list *list)
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

t_node	 *ft_lstnew(int	content)
{
    t_node *newNode;
    
    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
    	return (NULL);
    newNode->content = content;
	newNode->rank = 0;
	newNode->cost = 0;
	newNode->ra = -1;
	newNode->rb = -1;
	newNode->rra = -1;
	newNode->rrb = -1;
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
    t_node 	*currentNode = list->head;
	int		chunk_size;

	chunk_size = (list->size + CHUNK_NR - 1) / CHUNK_NR;
    if (currentNode == NULL)
    {
        ft_printf("List is empty.\n");
        return;
    }
    ft_printf("Linked List: ");
    while (currentNode->next != list->head)
    {
	ft_printf("%d(%d,%d) ",currentNode->content, currentNode->rank, currentNode->rank/chunk_size);
        currentNode = currentNode->next;
    }
	ft_printf("%d(%d,%d)\n",currentNode->content, currentNode->rank, currentNode->rank/chunk_size);
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
