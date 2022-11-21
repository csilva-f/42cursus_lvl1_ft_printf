/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:38:06 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/21 23:11:49 by csilva-f         ###   ########.fr       */
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

int	ft_count_hex(unsigned int n)
{
	unsigned int	nbr;
	int				count;

	nbr = n;
	count = 1;
	while (nbr > 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	ft_print_hex(unsigned int n, char c)
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
			if (n % 16 < 10)
				str[count - 1] = (n % 16) + '0';
			else
			{
				if (c == 'X')
					str[count - 1] = (n % 16) + 'A';
				else
					str[count - 1] = (n % 16) + 'a';
			}
			n /= 16;
			count--;
		}
		len = ft_print_str(str);
		free(str);
	}
	return (len);
}
