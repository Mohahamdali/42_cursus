/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:58:52 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/13 10:20:21 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	i = 0;
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dst < source || dst >= source + n)
		ft_memcpy(dst, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}
