/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:12:56 by akarasev          #+#    #+#             */
/*   Updated: 2022/11/18 19:57:31 by akarasev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{	
	int	i;
	int	cur;
	int	buff;

	i = 0;
	while (i < size - 1)
	{	
		cur = i + 1;
		while (cur < size)
		{
			if (tab[i] > tab[cur])
			{
				buff = tab[cur];
				tab[cur] = tab[i];
				tab[i] = buff;
			}
			++cur;
		}
		++i;
	}
}
