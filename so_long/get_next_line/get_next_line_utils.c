/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:11:28 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/13 10:26:47 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*dest;
	size_t	i;

	length = ft_strlen (src);
	i = 0;
	dest = ((char *)malloc ((length + 1)));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	length_source;
	size_t	i;

	i = 0;
	length_source = ft_strlen(src);
	if (dest_size == 0)
	{
		return (length_source);
	}
	while (src[i] != '\0' && i < dest_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length_source);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	result = ((char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_strlcpy (result, s1, ft_strlen(s1) + 1);
	ft_strlcat (result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	return (result);
}
