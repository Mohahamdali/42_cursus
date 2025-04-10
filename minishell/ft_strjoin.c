/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:56:06 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/10 10:57:43 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	result = ((char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!result)
		return (NULL);
	ft_strlcpy (result, s1, ft_strlen(s1) + 1);
	// result[ft_strlen(s1)] = '/';
	// result[ft_strlen(result) + 1] = '\0';
	ft_strlcat (result, s2, ft_strlen(result) + ft_strlen(s2) + 1);
	return (result);
}
