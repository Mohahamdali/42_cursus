#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H

#include <libc.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char    *get_next_line (int fd);
size_t	ft_strlen(const char *str);
#endif