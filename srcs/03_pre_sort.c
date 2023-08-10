/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <lwoiton@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:47:07 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/10 14:22:39 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_chunker(t_chnkr *cc)
{
	cc->up_crr_chnk = 0;
	cc->lo_crr_chnk = 1;
	cc->up_chnk_cntr = 0;
	cc->lo_chnk_cntr = 0;
	return (0);
}

void	partition(t_list *a, t_list *b)
{
	t_chnkr	cc;

	init_chunker(&cc);
	while (a->size > 3)
	{
		if (a->head->rank / a->chunk_size == cc.up_crr_chnk && \
				a->head->rank < (a->size + b->size) - 3)
			push_b(a, b, &cc);
		else if (a->head->rank / a->chunk_size == cc.lo_crr_chnk && \
				a->head->rank < (a->size + b->size) - 3)
			push_to_low_and_rotate(a, b, &cc);
		else
		{
			rotate1(a);
			ft_printf("ra\n");
		}
		increase_current_chunks(a, &cc);
	}
}

int	push_b(t_list *a, t_list *b, t_chnkr *cc)
{
	push(b, a);
	ft_printf("pb\n");
	cc->up_chnk_cntr++;
	return (0);
}

int	push_to_low_and_rotate(t_list *a, t_list *b, t_chnkr *cc)
{
	push(b, a);
	ft_printf("pb\n");
	if (a->head->next->rank / a->chunk_size > cc->lo_crr_chnk && \
		a->head->next->rank >= (a->size + b->size) - 3)
	{
		rotate2(a, b);
		ft_printf("rr\n");
	}
	else
	{
		rotate1(b);
		ft_printf("rb\n");
	}
	cc->lo_chnk_cntr++;
	return (0);
}

int	increase_current_chunks(t_list *a, t_chnkr *cc)
{
	if (cc->up_chnk_cntr == a->chunk_size)
	{
		cc->up_chnk_cntr = 0;
		cc->up_crr_chnk += 2;
	}
	else if (cc->lo_chnk_cntr == a->chunk_size)
	{
		cc->lo_chnk_cntr = 0;
		cc->lo_crr_chnk += 2;
	}
	return (0);
}