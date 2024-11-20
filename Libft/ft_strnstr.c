/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:10:19 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/20 20:58:51 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
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
