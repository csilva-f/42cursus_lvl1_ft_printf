/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:38:06 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/24 22:02:49 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_count_dig(unsigned int n)
{
	unsigned int	nbr;
	int				count;

	nbr = n;
	count = 1;
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_print_uns(unsigned int n)
{
	int				len;
	int				count;
	char			*str;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		count = ft_count_dig(n);
		str = (char *)malloc((count + 1) * sizeof(char));
		if (!str)
			return (0);
		str[count] = '\0';
		while (count > 0)
		{
			str[count - 1] = (n % 10) + 48;
			n /= 10;
			count--;
		}
		len = ft_print_str(str);
		free(str);
	}
	return (len);
}

void	ft_put_ptr(unsigned long long p, int *len)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16, len);
		ft_put_ptr(p % 16, len);
	}
	else
	{
		if (p < 10)
			(*len) += ft_print_chr(p + '0');
		else
			(*len) += ft_print_chr(p - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long p)
{
	int	len;

	if (!p)
		return (write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	ft_put_ptr(p, &len);
	return (len);
}
