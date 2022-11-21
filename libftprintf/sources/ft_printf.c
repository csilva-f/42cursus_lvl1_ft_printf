/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:16:58 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/21 22:12:00 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_conversion(va_list ap, char c)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len = ft_print_chr(va_arg(ap, int));
	else if (c == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		len = 0;
	else if (c == 'd' || c == 'i')
		len = ft_print_int(va_arg(ap, int));
	else if (c == 'u')
		len = ft_print_uns(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len = 0;
	return (len);
}

int	ft_printf(const char *argum, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	if (!argum)
		return (0);
	va_start(ap, argum);
	i = -1;
	len = 0;
	while (argum[++i] != '\0')
	{
		if (argum[i] == '%')
		{
			if (argum[++i] == '%')
				write(1, &argum[i], 1);
			else
				len = ft_conversion(ap, argum[i]);
		}
		else
			write(1, &argum[i], 1);
	}
	return (0);
}
