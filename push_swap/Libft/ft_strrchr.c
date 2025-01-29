/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:36:15 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:49 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = (int)ft_strlen(src);
	while (i >= 0)
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i--;
	}
	return (NULL);
}
