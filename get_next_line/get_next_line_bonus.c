/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:37:36 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/09 18:24:19 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer_static[OPEN_MAX];
	char		*len;
	char		*temp;

	if (fd < 0 || read(fd, buffer_static[0], 0) == -1)
	{
		if (fd > 0 && fd < 10240)
			clear_pointer (&buffer_static[fd]);
		return (NULL);
	}
	if (BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (clear_pointer(&buffer_static[fd]), NULL);
	buffer_static[fd] = ft_read_file (fd, buffer_static[fd]);
	if (buffer_static[fd] && !*buffer_static[fd])
		return (clear_pointer(&buffer_static[fd]), NULL);
	len = cat_buffer (buffer_static[fd]);
	if (!len || !*len)
		return (clear_pointer(&len), clear_pointer(&buffer_static[fd]), NULL);
	temp = buffer_static[fd];
	buffer_static[fd] = ft_strdup(buffer_static[fd] + ft_strlen(len));
	if (!buffer_static[fd])
		return (clear_pointer(&temp), clear_pointer(&len), NULL);
	clear_pointer(&temp);
	return (len);
}
