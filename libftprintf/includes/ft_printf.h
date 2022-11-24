/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:07:17 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/24 22:34:06 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_print_chr(char c);
int		ft_print_str(char *str);
int		ft_print_int(int n);
int		ft_print_uns(unsigned int n);
void	ft_print_hex(unsigned int n, char c, int *len);
int		ft_print_ptr(unsigned long long p);
int		ft_conversion(va_list ap, char c);
int		ft_printf(const char *argum, ...);

#endif
