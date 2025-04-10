/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:18:07 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/09 14:54:05 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int ft_strlen (const char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	length_source;
	size_t	i;

	i = 0;
	length_source = ft_strlen(src);
	if (dest_size == 0)
		return (length_source);
	while (src[i] != '\0' && i < dest_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length_source);
}
