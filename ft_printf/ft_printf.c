/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:36:45 by mhamdali          #+#    #+#             */
/*   Updated: 2024/12/03 18:39:30 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, int sign)
{
	char	*base;
	int		count;

	count = 0;
	if (sign == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_putnbr_base((n / 16), sign);
	}
	ft_putchar(base[n % 16]);
	count++;
	return (count);
}

void	ft_print(const char *format, va_list s, int *count)
{
	if (*format == 'c')
		*count += ft_putchar(va_arg(s, int));
	else if (*format == 's')
		*count += ft_putstr(va_arg(s, char *));
	else if (*format == 'd' || *format == 'i')
		*count += ft_putnbr(va_arg(s, int));
	else if (*format == 'u')
		*count += ft_putnbr_unsgined(va_arg(s, unsigned int));
	else if (*format == 'p')
		*count += ft_putnbr_hex(va_arg(s, unsigned long));
	else if (*format == 'x')
		*count += ft_putnbr_base(va_arg(s, unsigned int), 0);
	else if (*format == 'X')
		*count += ft_putnbr_base(va_arg(s, unsigned int), 1);
	else
		*count += write(1, format, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;


	i = 0;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			i += ft_putchar('%');
			format++;
		}
		else if (*format == '%' && *(format + 1) != '\0')
		{
			ft_print(format + 1, ptr, &i);
			format++;
		}
		else if (*format != '%')
		{
			write(1, format, 1);
			i++;
		}
		format++;
	}
	return (va_end (ptr), i);
}
