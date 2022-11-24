/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/24 22:09:29 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_chr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (i);
}

int	ft_print_int(int n)
{
	int		len;
	char	*str_nbr;

	str_nbr = ft_itoa(n);
	len = ft_print_str(str_nbr);
	free(str_nbr);
	return (len);
}

void	ft_print_hex(unsigned int n, char c, int *len)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, c, len);
		ft_print_hex(n % 16, c, len);
	}
	else
	{
		if (n < 10)
			(*len) += ft_print_chr(n + '0');
		else if (c == 'x')
			(*len) += ft_print_chr(n + 'a' - 10);
		else if (c == 'X')
			(*len) += ft_print_chr(n + 'A' - 10);
	}
}
