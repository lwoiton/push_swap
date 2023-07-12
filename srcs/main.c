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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void	chunk_builder(t_list *list)
{
	int	*sorted_list;
	int	i;
	t_node	*tmp;

	sorted_list = (int*)malloc(list->size * sizeof(int));
	i = 0;
	tmp = list->head;
	while(i < list->size)
	{
		sorted_list[i] = tmp->content;
		tmp = tmp->next;
		++i;
	}
	ft_sort_int_tab(sorted_list, list->size);
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
	else if (argc == 2)
	{
		i = 0;
		parsed_params = ft_split(argv[1], ' ');
		while (parsed_params[i] != NULL)
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(parsed_params[i])));
			++i;
		}	
	}
	else
	{
	
	}
	displayList(&list);
    	return 0;
}
