/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:07:17 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/21 23:19:31 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT__PRINTFH

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_print_chr(char c);
int		ft_print_str(char *str);
int		ft_print_int(int n);
int		ft_print_uns(unsigned int n);
int		ft_print_hex(unsigned int n, char c);

#endif
