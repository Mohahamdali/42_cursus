/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:02:30 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/18 22:28:53 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*sub_str;

	i = 0;
	len_s = ft_strlen (src);
	if (!src)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub_str = ((char *)malloc (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = src[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
