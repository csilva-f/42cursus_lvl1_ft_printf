/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:38:06 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 22:12:55 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	ft_fill_int_zeros(t_flags *flags, char **u_print)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*u_print);
	if (flags->dot && (flags->dec > len || flags->dec == 0))
	{
		tmp = memset((char *)malloc(sizeof(char) * (flags->dec + 1)), 
				(int) '0', flags->dec);
		tmp[flags->dec] = '\0';
		ft_strlcpy(&(tmp[flags->dec - len]), *u_print, len + 1);
		free(*u_print);
		*u_print = tmp;
	}
	else if (flags->dot == 0 && flags->zero)
	{
		flags->nbr = ft_max(flags->nbr, len);
		tmp = memset((char *)malloc(sizeof(char) * (flags->nbr + 1)), 
				(int) '0', flags->nbr);
		tmp[flags->nbr] = '\0';
		ft_strlcpy(&(tmp[flags->nbr - len]), *u_print, flags->nbr + 1);
		free(*u_print);
		*u_print = tmp;
	}
}

int	ft_print_uns(t_flags *flags, long value)
{
	int		len;
	char	*u_print;
	int		str_len;

	len = 0;
	u_print = ft_itoa(value);
	str_len = ft_strlen(u_print);
	if (value < 0)
		flags->nbr = ft_max(flags->nbr, str_len);
	if ((flags->dot && (flags->dec > str_len || flags->dec == 0))
		|| flags->zero)
		ft_fill_int_zeros(flags, &u_print);
	if ((flags->f == 'd' || flags->f == 'i') && flags->plus)
		ft_neg_str(&u_print, '+');
	if ((flags->f == 'd' || flags->f == 'i') && flags->plus == 0
		&& flags->space)
		ft_neg_str(&u_print, ' ');
	if (flags->minus)
		len += ft_printf("%-*s", flags->nbr, u_print);
	else
		len += ft_printf("%*s", flags->nbr, u_print);
	free(u_print);
	return (len);
}

int	ft_print_int(t_flags *flags, int nbr, int uns)
{
	int		len;
	char	*i_print;

	len = 0;
	if (nbr >= 0)
		return (ft_print_uns(flags, nbr));
	i_print = ft_itoa2(((long)nbr) * -1, uns);
	len += ft_print_neg(flags, i_print);
	return (len);
}

char	*ft_hex(unsigned long ptr)
{
	unsigned long	ptr2;
	int				len;
	char			*str_hex;

	ptr2 = ptr;
	len = 0;
	if (ptr == 0)
		len = 1;
	while (ptr2 > 0 && len++ >= 0)
		ptr2 /= 16;
	str_hex = malloc(sizeof(char) * (len + 1));
	if (!str_hex)
		return (NULL);
	str_hex[len] = '\0';
	len--;
	while (len >= 0)
	{
		str_hex[len] = "0123456789abcdef"[ptr % 16];
		ptr = ptr / 16;
		len--;
	}
	return (str_hex);
}
