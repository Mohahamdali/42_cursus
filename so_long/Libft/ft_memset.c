/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:00:41 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/13 10:20:24 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *ptr, int v, size_t count)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)ptr;
	value = (unsigned char )v;
	i = 0;
	while (i < count)
	{
		p[i] = value;
		i++;
	}
	return (ptr);
}
