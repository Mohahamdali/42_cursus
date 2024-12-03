/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:49:41 by mhamdali          #+#    #+#             */
/*   Updated: 2024/12/02 15:26:52 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_printf(const char *s, ...);
int	ft_putnbr(int i);
int	ft_putnbr_unsgined(unsigned int n);
int	ft_putnbr_hex(unsigned long n);
int	ft_putnbr_base(unsigned int n, int sign);
#endif
