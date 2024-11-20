/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:42:12 by mhamdali          #+#    #+#             */
/*   Updated: 2024/11/15 20:28:50 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	char	*result;

	count = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[count] && ft_strchr (set, s1[count]) != NULL)
	{
		count++;
	}
	i = ft_strlen(s1);
	while (i > 0 && ft_strrchr(set, s1[i - 1]) != NULL)
	{
		i--;
	}
	if (count == i)
		return (ft_strdup(""));
	result = ft_substr(s1, count, i - count);
	return (result);
}
