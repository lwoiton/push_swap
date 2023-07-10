/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:19 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/10 19:36:59 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pus_swap.h"

int	main(char *argv[], int argc)
{
	check_input(argv, argc);
    t_list list;
    ft_list_init(&list);
    
    int num1 = 1;
    int num21 = 21;
    int num61 = 61;
    int num81 = 81;
    int num51 = 51;
    int num2 = 2;
    int num3 = 3;

    ft_lstadd_back(&list, ft_lstnew(&num1));
    ft_lstadd_back(&list, ft_lstnew(&num21));
    ft_lstadd_back(&list, ft_lstnew(&num61));
    ft_lstadd_back(&list, ft_lstnew(&num81));
    ft_lstadd_back(&list, ft_lstnew(&num51));
    ft_lstadd_back(&list, ft_lstnew(&num3));
    ft_lstadd_back(&list, ft_lstnew(&num2));
    displayList(&list);
    
    return 0;
}















