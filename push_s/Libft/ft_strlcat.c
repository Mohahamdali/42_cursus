/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:12:59 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:27 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	space_left;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size == 0)
		return (src_len);
	if (dest_len >= size)
		return (size + src_len);
	space_left = size - dest_len - 1;
	while (src[i] != '\0' && i < space_left)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
