/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 22:50:49 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(t_flags *flags, unsigned long ptr)
{
	int		len;
	char	*p_print;
	char	*tmp;

	len = 0;
	if (ptr == 0)
		p_print = "(nil)";
	else
	{
		p_print = ft_hex(ptr);
		tmp = ft_strjoin("0x", p_print);
		free(p_print);
		p_print = tmp;
	}
	if (flags->minus == 1)
		len += ft_printf("%-*s", flags->nbr, p_print);
	else
		len += ft_printf("%*s", flags->nbr, p_print);
	free(p_print);
	return (len);
}

static void	ft_toupper_str(char **str)
{
	char	*p;

	p = *str;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
		p++;
	}
}

static int	ft_get_hex_zeros(t_flags *flags, char *x_print)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(x_print);
	if (flags->card == 1 && flags->f == 'x' && x_print[0] != '0')
	{
		len += 2;
		ft_print_s("0x");
	}
	else if (flags->card == 1 && flags->f == 'X' && x_print[0] != '0')
	{
		len += 2;
		ft_print_s("0X");
	}
	if (flags->card == 1)
		flags->nbr -= 2;
	if (flags->zero == 1 && flags->dot == 0)
	{
		while ((flags->nbr-- - str_len) > 0)
		{
			len++;
			ft_print_c('0');
		}
	}
	else
	{
		while ((flags->nbr-- - str_len) > 0)
		{
			len++;
			ft_print_c(' ');
		}
	}
	len += ft_strlen(x_print);
	ft_print_s(x_print);
	return (len);
}

static int	ft_get_hex_len(t_flags *flags, char *x_print)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(x_print);
	if (flags->card == 1 && x_print[0] != '0')
		str_len += 2;
	if (flags->card == 1)
	{
		if (flags->card == 1 && flags->f == 'X')
		{
			len += 2;
			ft_print_s("0X");
		}
		else if (flags->card == 1 && flags->f == 'x')
		{
			len += 2;
			ft_print_s("0x");
		}
		if (flags->card == 1)
		{
			len += str_len - 2;
			ft_print_s(x_print);
		}
		else
		{
			len += str_len;
			ft_print_s(x_print);
		}
		while ((flags->nbr--) - str_len > 0)
		{
			len++;
			ft_print_c(' ');
		}
	}
	else
		return (ft_get_hex_zeros(flags, x_print));
	return (len);
}

int	ft_print_hex(t_flags *flags, unsigned int nbr)
{
	int		len;
	char	*s;
	char	*tmp;

	len = 0;
	s = ft_hex(nbr);
	if (!s)
		return (0);
	if (flags->f == 'X')
		ft_toupper_str(&s);
	if (flags->f && ((flags->dec) > (int)ft_strlen(s) || !(flags->dec)))
	{
		tmp = calloc(flags->dec + 1, sizeof(char));
		tmp = ft_memset(tmp, '0', flags->dec);
		tmp[flags->dec] = '\0';
		ft_strlcpy(tmp + (flags->dec - ft_strlen(s)), s, ft_strlen(s) + 1);
		free(s);
		s = tmp;
	}
	if (flags->nbr >= 0)
		len += ft_get_hex_len(flags, s);
	else
	{
		len += ft_strlen(s);
		ft_print_s(s);
	}
	free(s);
	return (len);
}
