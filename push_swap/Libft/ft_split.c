/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:23:22 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:10 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

static int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	my_strlen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
	{
		len++;
	}
	return (len);
}

static void	free_all(char **result, int c)
{
	size_t	i;

	i = 0;
	while (i < (size_t)c)
		free (result[i++]);
	free(result);
}

static void	allocated_d(char **result, const char *s, size_t i, char c)
{
	result[i] = malloc(my_strlen(s, c) + 1);
	if (!result[i])
	{
		free_all(result, i);
		return ;
	}
	ft_strlcpy (result[i], s, my_strlen(s, c) + 1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	count = count_word (s, c);
	result = malloc ((count + 1) * sizeof(char *));
	i = 0;
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (i < (size_t)count)
		{
			allocated_d(result, s, i, c);
			i++;
		}
		s += my_strlen(s, c);
	}
	result[i] = NULL;
	return (result);
}
