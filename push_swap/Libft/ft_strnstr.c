/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:10:19 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:44 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!s && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)s);
	while (s[i] && i < len)
	{
		x = 0;
		while (s[i + x] == needle[x] && (i + x) < len)
		{
			x++;
			if (needle[x] == '\0')
			{
				return ((char *)&s[i]);
			}
		}
		i++;
	}
	return (NULL);
}
