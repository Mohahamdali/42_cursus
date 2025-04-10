# ifndef MINISHELL
# define MINISHELL


#include <libc.h>
#include <readline/readline.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int     ft_strlen (const char *str);
#endif