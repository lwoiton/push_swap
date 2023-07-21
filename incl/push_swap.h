/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:05:04 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/21 12:07:02 by luca             ###   ########.fr       */
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
	int	min_rotations_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list 
{
    t_node	*head;
    int	size;
}	t_list;

t_node	*ft_lstnew(int	content);
void	ft_lstadd_front(t_list *lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstadd_back(t_list *lst, t_node *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void ft_list_init(t_list *list);
void displayList(t_list *list);
void	chunk_builder(t_list *list);
void    ft_sort_int_tab(int *tab, int size);
int	partition(t_list *A, t_list *B);
int	sort_three(t_list *A);
int	swap(t_list *list);
int	push(t_list *dst, t_list *src);
int	rotate1(t_list *list);
int	rotate2(t_list *list_A, t_list *list_B);
int	reverse_rotate1(t_list *list);
int	reverse_rotate2(t_list *list_A, t_list *list_B);
int	execute(t_list *A, t_list *B, t_node *sel_node)
t_node *find_min_cost(t_list *B);
int	calculate_costs(t_list *B),
int	max(int a, int b);
int	calculate_rotations(t_list *A, t_list *B);
int	find_position_in_a(t_list *A, t_node *curr_B);

#endif
