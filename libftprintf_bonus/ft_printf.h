/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:07:17 by csilva-f          #+#    #+#             */
/*   Updated: 2023/04/02 23:00:43 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		dot;
	int		nbr;
	int		dec;
	int		minus;
	int		plus;
	int		card;
	int		space;
	int		zero;
	int		ast;
	char	f;
}	t_flags;

int			ft_abs(int c);
int			ft_count_dig(int nbr);
int			init_flags(t_flags **flags);
int			ft_get_nbr(const char *argum);
int			get_flag_nbrs(t_flags *flags, const char *argum, va_list *ap);
int			get_flags(const char *argum, t_flags *flags, va_list *ap);
void		ft_print_c(char c);
void		ft_print_prc_aux(t_flags *flags, int *len);
int			ft_print_prc(t_flags *flags);
int			ft_print_chr(t_flags *flags, char c);
void		ft_print_s(char *str);
int			ft_print_str(t_flags *flags, char *str);
char		*ft_itoa2(long int n, int uns);
void		ft_neg_str(char **i_print, char c);
int			ft_print_uns(t_flags *flags, long value);
int			ft_print_neg(t_flags *flags, char *i_print);
int			ft_print_int(t_flags *flags, int nbr, int uns);
char		*ft_hex(unsigned long ptr);
int			ft_print_ptr(t_flags *flags, unsigned long ptr);
int			ft_print_hex(t_flags *flags, unsigned int nbr);
int			ft_conversion(t_flags *flags, va_list *ap);
int			get_len_to_print(const char **argum, va_list *ap);
int			ft_printf(const char *argum, ...);

#endif
