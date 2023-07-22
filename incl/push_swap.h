/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:05:04 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/22 02:07:36 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

#define TODO(s) ft_printf("%s:%s:%d: %s\n", __FILE__, __func__, __LINE__, s);
#define CHUNK_NR 8
#define NOT_IN_CHUNK_PANELTY 20
#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_node
{
	int	content;
	int	rank;
	int	cost;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list 
{
    t_node	*head;
    	int	size;
	int	minRank;
	int	maxRank;
}	t_list;

//-------------------------00_linked_list_utils.c---------------------------//
void	ft_list_init(t_list *list);
t_node	*ft_lstnew(int	content);
int	ft_lstadd_back(t_list *list, t_node *node);

//-------------------------00_rotate_operations.c---------------------------//
int	rotate1(t_list *list);
int	rotate2(t_list *A, t_list *B);
int	reverse_rotate1(t_list *list);
int	reverse_rotate2(t_list *A, t_list *B);

//--------------------------00_stack_operations.c---------------------------//
int	swap(t_list *list);
int	push(t_list *dst, t_list *src);

//--------------------------------00_main.c---------------------------------//
void	chunk_builder(t_list *A);
t_node	*findMinCost(t_list *B);
int	sortThree(t_list *A);
int	partition(t_list *A, t_list *B);

//----------------------------01_parse_input.c-------------------------------//
t_list	*parseInput(int argc, char* argv[]);
int	parseString(char *argv[], t_list *A);
int	parseArgs(int argc, char *argv[], t_list *A);

//---------------------------02_analyse_ranks.c------------------------------//
void	analyseRanks(t_list *A);
void	ft_sort_int_tab(int *tab, int size);
void	assignRanks(t_list *A, int *sorted_A);

//-----------------------------03_pre_sort.c---------------------------------//

//------------------------04_calculate_rotations.c---------------------------//
int	calcRotations(t_list *A, t_list *B);
int	getRotations_A(t_list *A, int nextRank);
int	resetRotations(t_list *B);
int	setRotationDirection(t_list *A, t_list *B);

//-----------------------------05_read_ranks.c-------------------------------//
int	getMinRank(t_list *A);
int	getMaxRank(t_list *A);
int	getNextRank(t_list *A, int currRank_BN);

//--------------------------06_calculate_costs.c-----------------------------//
int	calcCosts(t_list *A, t_list *B);
int	accountAdjacency(t_list *A, t_node *curr_B);
int	accountChunkCost(t_list *A, t_list *B, t_node *curr_B);
int	max(int a, int b);

//----------------------------07_execute_sort.c------------------------------//
void	executeDoubleRotation(t_list *A, t_list *B, t_node *sel_node);
void	executeRotation_A(t_list *A, t_node *sel_node);
void	executeRotation_B(t_list *B, t_node *sel_node);
int	execute(t_list *A, t_list *B, t_node *sel_node);


//-----------------------utils_display_linked_list.c-------------------------//
void displayList(t_list *list);
void printStacks(t_list *A, t_list *B);
#endif
