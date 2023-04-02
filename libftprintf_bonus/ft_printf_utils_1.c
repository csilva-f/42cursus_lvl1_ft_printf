/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 19:39:57 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c)
{
	write(1, &c, 1);
}

void	ft_print_prc_aux(t_flags *flags, int *len)
{
	if (flags->zero == 1)
	{
		while (flags->nbr-- > 1)
		{
			len++;
			ft_print_c('0');
		}
	}
	else
	{
		while (flags->nbr-- > 1)
		{
			len++;
			ft_print_c(' ');
		}
	}
	len++;
	ft_print_c('%');

}

int	ft_print_prc(t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
	{
		len += 1;
		ft_print_c('%');
		while (flags->nbr-- > 1)
		{
			len++;
			ft_print_c(' ');
		}
	}
	else
		ft_print_prc_aux(flags, &len);
	return (len);
}

int	ft_print_chr(t_flags *flags, char c)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
	{
		len++;
		ft_print_c(c);
		while (flags->nbr-- > 1)
		{
			len++;
			ft_print_c(' ');
		}
	}
	else
	{
		while (flags->nbr-- > 1)
		{
			len++;
			ft_print_c(' ');
		}
		len++;
		ft_print_c(c);
	}
	return (len);
}

void	ft_print_s(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}
