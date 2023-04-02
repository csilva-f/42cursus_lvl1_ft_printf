/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 23:01:42 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flags(t_flags *flags, char *s_print)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(s_print);
	if (flags->minus == 1)
	{
		len += str_len;
		ft_print_s(s_print);
		while ((flags->nbr--) - str_len > 0)
		{
			len++;
			ft_print_c(' ');
		}
	}
	else
	{
		while ((flags->nbr--) - str_len > 0)
		{
			len++;
			ft_print_c(' ');
		}
		len += str_len;
		ft_print_s(s_print);
	}
	return (len);
}

int	ft_print_str(t_flags *flags, char *str)
{
	int		len;
	char	*tmp;
	char	*s_print;

	len = 0;
	tmp = NULL;
	if (!str)
		s_print = "(null)";
	else
		s_print = str;
	if (flags->dec < 0)
		flags->dec = ft_strlen(s_print);
	if (flags->dot == 1 && (flags->dec < (int)ft_strlen(s_print)))
	{
		tmp = (char *)ft_calloc(flags->dec + 1, sizeof(char));
		ft_strlcpy(tmp, s_print, flags->dec + 1);
		free(s_print);
		s_print = tmp;
	}
	if (flags->nbr > 0)
		len += ft_check_flags(flags, s_print);
	else
	{
		len += ft_strlen(s_print);
		ft_print_s(s_print);
	}
	free(s_print);
	return (len);
}

void	ft_neg_str(char **i_print, char c)
{
	char	*tmp;
	int		str_len;

	str_len = ft_strlen(*i_print);
	tmp = (char *)malloc((str_len + 2) * sizeof(char));
	tmp[0] = c;
	tmp[str_len + 1] = '\0';
	ft_strlcpy(tmp + 1, *i_print, (str_len + 1));
	free(*i_print);
	*i_print = tmp;
}

static void	ft_get_int(char **i_print, int n_c)
{
	int		str_len;
	char	*int_str;

	str_len = ft_strlen(*i_print);
	if (n_c <= str_len)
	{
		ft_neg_str(i_print, '-');
		return ;
	}
	int_str = ft_memset((char *)malloc(sizeof(char) * (n_c + 2)), 
			(int) '0', n_c + 1);
	int_str[0] = '-';
	int_str[n_c + 1] = '\0';
	ft_strlcpy(int_str + n_c - str_len + 1, *i_print, str_len + 1);
	free(*i_print);
	*i_print = int_str;
}

int	ft_print_neg(t_flags *flags, char *i_print)
{
	int		len;

	len = 0;
	if (flags->dot)
		ft_get_int(&i_print, flags->dec);
	else if (flags->dot == 0 && flags->minus == 0 && flags->zero == 1)
		ft_get_int(&i_print, flags->nbr - 1);
	else
		ft_neg_str(&i_print, '-');
	if (flags->minus)
		len += ft_printf("%-*s", flags->nbr, i_print);
	else
		len += ft_printf("%*s", flags->nbr, i_print);
	free(i_print);
	return (len);
}
