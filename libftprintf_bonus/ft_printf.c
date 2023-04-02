/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:16:58 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 22:53:55 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flags(const char *argum, t_flags *flags, va_list *ap)
{
	if (*argum == '-')
		flags->minus = 1;
	else if (*argum == '+')
		flags->plus = 1;
	else if (*argum == '0' && flags->dot == 0)
		flags->zero = 1;
	else if (*argum == '#')
		flags->card = 1;
	else if (*argum == ' ')
		flags->space = 1;
	else if (*argum == '+')
		flags->plus = 1;
	else if (*argum == '.')
		flags->dot = 1;
	else if ((*argum >= '1' && *argum <= '9') || *argum == '*')
		return(get_flag_nbrs(flags, argum, ap));
	return (1);
}

int	ft_conversion(t_flags *flags, va_list *ap)
{
	int		len;

	len = 0;
	if (flags->f == 'c')
		len += ft_print_chr(flags, va_arg(*ap, int));
	else if (flags->f == 's')
		len += ft_print_str(flags, va_arg(*ap, char *));
	else if (flags->f == 'p')
		len += ft_print_ptr(flags, va_arg(*ap, unsigned long long));
	else if (flags->f == 'd' || flags->f == 'i')
		len += ft_print_int(flags, va_arg(*ap, long int), 0);
	else if (flags->f == 'u')
		len += ft_print_uns(flags, va_arg(*ap, int));
	else if (flags->f == 'x' || flags->f == 'X')
		len += ft_print_hex(flags, (va_arg(*ap, unsigned int)));
	else if (flags->f == '%')
		len += ft_print_prc(flags);
	return (len);
}

int	get_len_to_print(const char **argum, va_list *ap)
{
	t_flags	*flags;
	int		c;
	int		len;

	c = init_flags(&flags);
	if (c == -1)
		return (0);
	while (**argum != 'c' && **argum != 's' && **argum != 'p' && **argum != 'd' && 
			**argum != 'i' && **argum != 'u' && **argum != 'x' && **argum != 'X')
		(*argum) += get_flags(*argum, flags, ap); 
	flags->f = **argum;
	len = ft_conversion(flags, ap);
	free(flags);
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
			len += get_len_to_print(&argum, &ap);
		else
		{
			len++;
			ft_print_c(argum[i]);
		}
	}
	va_end(ap);
	return (len);
}
