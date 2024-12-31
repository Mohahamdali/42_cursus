#include "get_next_line.h"

void f()
{
	system("leaks a.out");
}
void clear_pointer (char ** ptr)
{
	free(*ptr);
	*ptr = NULL;
}
char *cat_buffer (char *str)
{
	int		i;
	int		len;
	char	*reserve;
	i = 0;
	len = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = i;
	if (str[i] == '\n')
		len++;
	reserve = malloc (len + 1);
	if (!reserve)
		return (free(reserve),NULL);
	i = 0;
	while (i < len)
	{
		reserve[i] = str[i];
		i++;
	}
	reserve [len] = '\0';
	return (reserve);
}

char *ft_read_file (int fd,char *buffer)
{
	char *reserve;
	int check;
	reserve = malloc ((size_t)BUFFER_SIZE + 1);
	if (!reserve)
		return (NULL);
  
	while (ft_strchr(buffer,'\n') == NULL)
	{
		check = read (fd, reserve, BUFFER_SIZE);
		if (check == -1)
		{
			free(reserve);
			return (free(buffer),NULL);
		}
		if (check == 0)
		{
			free (reserve);
			return (buffer);
		}
		reserve[check] = '\0';
		buffer = ft_strjoin(buffer,reserve);
		if(!buffer)
			return(clear_pointer(&reserve),clear_pointer(&buffer),NULL);
	}
	free(reserve);
	return (buffer);
}


char *get_next_line (int fd)
{
   static char *buffer_static;
   char *len;
   char *temp;

   if (fd < 0 || BUFFER_SIZE < 0)
	return (clear_pointer(&buffer_static), NULL);
	buffer_static = ft_read_file (fd,buffer_static);
	if (!buffer_static || !*buffer_static)
		return (clear_pointer(&buffer_static), NULL);
	len = cat_buffer (buffer_static);

	if (!len && !*len)
		return (clear_pointer(&len),NULL);
	temp = buffer_static;
    buffer_static = ft_strdup(buffer_static + ft_strlen(len));
	clear_pointer(&temp);
	return (len);
}

// int main ()
// {

// 	int fd = open ("test.txt",O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s",s);
// 	free(s);
// 	printf("%s",s);
// 	close(fd);
	
// }