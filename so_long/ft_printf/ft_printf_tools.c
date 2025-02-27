/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:56:35 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/24 13:35:53 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_putnbr(int i)
{
	int	count;

	count = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
		count++;
	}
	if (i > 9)
	{
		count += ft_putnbr(i / 10);
	}
	ft_putchar(i % 10 + '0');
	count++;
	return (count);
}

int	ft_putnbr_unsgined(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsgined(n / 10);
	}
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}

int	ft_putnbr_hex(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_putnbr_hex (n / 16);
	}
	if (!(n > 15))
	{
		ft_putstr("0x");
		count += 2;
	}
	ft_putchar(base[n % 16]);
	count++;
	return (count);
}
