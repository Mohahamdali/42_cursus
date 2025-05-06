/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:44:52 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/19 14:52:50 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


void check_overflow (long n)
{
    if (n == 0|| n < INT_MIN || n > INT_MAX)
    {
        write(2,"Error\n",6);
        exit(1);
    }
}

int	ft_atoi(const char *str)
{
	unsigned long		result;
	size_t				i;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
    check_overflow (result * sign);
	return ((int)result * sign);
}