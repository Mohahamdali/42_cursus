/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:56:35 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/22 06:12:24 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c, int *counter)
{
    write(1,&c,1);
    
}

void ft_putstr(const char *s,int *counter)
{
    while (*s)
    {
        write(1,s,1);
        s++;
    }
}
