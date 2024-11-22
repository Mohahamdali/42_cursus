/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:36:45 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/22 06:10:07 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_putchar (char c,int *counter);
void	ft_putstr(const char *s,int *counter);


void ft_print(const char *format,va_list s,int *counter)
{
	if (*format == '%')
		format++;
	if (*format == 'c')
			ft_putchar(va_arg(s, int),counter);
}

int ft_printf(const char *format, ...)
{
	va_list ptr;
	int count = 0;
	va_start(ptr,format);
	if (*format == '%')
		format++;
	if (*format == 'c')
		ft_print(format,ptr,&count);
		printf("%d",count);
    return (2);
}

int main ()
{
	char x = 'Z';
	char z = 'a';
	char d[] = "mohamed";
  ft_printf("");

// printf("%c\t",x);
  
}