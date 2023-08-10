/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:24:54 by lwoiton           #+#    #+#             */
/*   Updated: 2023/01/21 18:31:13 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_to_nbr(char c, int nbr)
{
	nbr = nbr * 10 + (int)(c - 48);
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	nbr;

	n = 1;
	nbr = 0;
	while (*nptr && (*nptr == 32 || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-')
	{
		n = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = ft_char_to_nbr(*nptr, nbr);
		nptr++;
	}
	return (nbr * n);
}
