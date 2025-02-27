/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:15:48 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/13 10:26:59 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	clear_pointer(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*cat_buffer(char *str)
{
	int		i;
	int		len;
	char	*reserve;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	len = i;
	if (str[i] == '\n')
		len++;
	reserve = malloc (len + 1);
	if (!reserve)
		return (clear_pointer(&str), NULL);
	i = 0;
	while (i < len)
	{
		reserve[i] = str[i];
		i++;
	}
	reserve [len] = '\0';
	return (reserve);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*reserve;
	int		check;

	reserve = malloc ((size_t)BUFFER_SIZE + 1);
	if (!reserve)
		return (clear_pointer(&buffer), NULL);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		check = read(fd, reserve, BUFFER_SIZE);
		if (check == -1)
		{
			clear_pointer (&reserve);
			return (clear_pointer(&buffer), NULL);
		}
		if (check == 0)
			return (clear_pointer(&reserve), buffer);
		reserve[check] = '\0';
		buffer = ft_strjoin(buffer, reserve);
		if (!buffer)
			return (clear_pointer(&reserve), NULL);
	}
	clear_pointer (&reserve);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer_static;
	char		*len;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, buffer_static, 0) == -1)
		return (clear_pointer(&buffer_static), NULL);
	buffer_static = ft_read_file (fd, buffer_static);
	if (buffer_static && !*buffer_static)
		return (clear_pointer(&buffer_static), NULL);
	len = cat_buffer (buffer_static);
	if (!len || !*len)
		return (clear_pointer(&len), clear_pointer(&buffer_static), NULL);
	temp = buffer_static;
	buffer_static = ft_strdup(buffer_static + ft_strlen(len));
	if (!buffer_static)
		return (clear_pointer(&temp), clear_pointer(&len), NULL);
	clear_pointer(&temp);
	return (len);
}
