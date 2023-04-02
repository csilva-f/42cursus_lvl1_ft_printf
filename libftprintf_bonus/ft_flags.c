/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 18:46:34 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

int	ft_count_dig(int nbr)
{
	int	dig;
	
	dig = 1;
	if (nbr == 0)
		return (dig);
	while (nbr > 0)
	{
		nbr /= 10;
		dig++;
	}
	return (dig);
}

int	init_flags(t_flags **flags)
{
	*flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	(*flags)->card = 0;
	(*flags)->dec = 0;
	(*flags)->dot = 0;
	(*flags)->minus = 0;
	(*flags)->nbr = 0;
	(*flags)->plus = 0;
	(*flags)->space = 0;
	(*flags)->zero = 0;
	(*flags)->ast = 0;
	return (0);
}

int	ft_get_nbr(const char *argum)
{
	int	res;

	res = 0;
	while (*argum >= '1' && *argum <= '9')
	{
		res = res * 10 + (*argum - '0');
		argum++;
	}
	return (res);
}

int	get_flag_nbrs(t_flags *flags, const char *argum, va_list *ap)
{
	int	nbr;

	if (*argum == '*')
	{
		flags->ast = 1;
		nbr = va_arg(*ap, int);
	}
	else
		nbr = ft_get_nbr(argum);
	if (flags->dot == 0)
	{
		if (nbr < 0)
			flags->minus = 1;
		flags->nbr = ft_abs(nbr);
	}
	else
		flags->dec = nbr;
	if (flags->ast == 1)
		return (1);
	return (ft_count_dig(ft_abs(nbr)));
}
