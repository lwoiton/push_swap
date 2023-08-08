/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:05:04 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/07 12:27:16 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define CHUNK_NR 5
# define NOT_IN_CHUNK_PANELTY 20
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				content;
	int				rank;
	int				cost;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list 
{
	t_node	*head;
	int		size;
	int		min_rank;
	int		max_rank;
}	t_list;

//-------------------------00_linked_list.c---------------------------//
void	ft_list_init(t_list *list);
t_node	*ft_lstnew(int content);
int		ft_lstadd_back(t_list *list, t_node *node);

//-------------------------00_rotate_operations.c---------------------------//
int		rotate1(t_list *list);
int		rotate2(t_list *a, t_list *b);
int		reverse_rotate1(t_list *list);
int		reverse_rotate2(t_list *a, t_list *b);

//--------------------------00_stack_operations.c---------------------------//
int		swap(t_list *list);
int		push(t_list *dst, t_list *src);

//--------------------------------00_main.c---------------------------------//
void	chunk_builder(t_list *a);
t_node	*find_min_cost(t_list *b);
int		sort_three(t_list *a);
void	partition(t_list *a, t_list *b);

//----------------------------01_parse_input.c-------------------------------//
int		parse_input(int argc, char *argv[], t_list *a);
int		parse_string(char *argv[], t_list *a);
int		parse_args(int argc, char *argv[], t_list *a);

//---------------------------02_analyse_ranks.c------------------------------//
void	analyse_ranks(t_list *a);
void	ft_sort_int_tab(int *tab, int size);
void	assign_ranks(t_list *a, int *sorted_a);
void	ft_sort_int_tab(int *sorted_a, int size);

//-----------------------------03_pre_sort.c---------------------------------//

//------------------------04_calculate_rotations.c---------------------------//
int		calc_rotations(t_list *a, t_list *b);
int		get_rotations_a(t_list *a, int next_rank);
int		reset_rotations(t_list *b);
int		set_rotation_direction(t_list *a, t_list *b);

//-----------------------------05_read_ranks.c-------------------------------//
int		get_min_rank(t_list *a);
int		get_max_rank(t_list *a);
int		get_next_rank(t_list *a, int curr_rank_bn);

//--------------------------06_calculate_costs.c-----------------------------//
int		calc_costs(t_list *a, t_list *b);
int		account_adjacency(t_list *a, t_node *curr_b);
int		account_chunk_cost(t_list *a, t_list *b, t_node *curr_b);
int		max(int a, int b);

//----------------------------07_execute_sort.c------------------------------//
void	execute_double_rotation(t_list *a, t_list *b, t_node *sel_node);
void	execute_rotation_a(t_list *a, t_node *sel_node);
void	execute_rotation_b(t_list *b, t_node *sel_node);
int		execute(t_list *a, t_list *b, t_node *sel_node);

//-----------------------utils_display_linked_list.c-------------------------//
void	display_list(t_list *list);
void	print_stacks(t_list *a, t_list *b);
#endif
