/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:05:04 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/11 17:59:53 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#define TODO(s) printf("%s:%s:%d: %s\n", __FILE__, __func__, __LINE__, s);

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list 
{
    t_node	*head;
    t_node	*tail;
    int	size;
}	t_list;


// LIBFT FUNCTIONS
t_node	*ft_lstnew(int	content);
void	ft_lstadd_front(t_list *lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstadd_back(t_list *lst, t_node *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// main.c functions
int		example_list();


// errors.c functions
void	error_exit();
int		input_check(char *argv[], int argc);

#endif
