/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:44:52 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/08 17:59:32 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	handle_overflow(unsigned long result, int sign)
{
	if ((result >= 9223372036854775807) && sign == 1)
		return (-1);
	else if (result >= 9223372036854775807 && sign == -1)
		return (0);
	return (result);
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
		if (result >= 9223372036854775807)
			return (handle_overflow(result, sign));
		i++;
	}
	return ((int)result * sign);
}
