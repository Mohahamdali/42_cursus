# ifndef MINISHELL
# define MINISHELL


#include <libc.h>
#include <readline/readline.h>
#include <unistd.h>

typedef struct s_redirect 
{
    char *filename;
    int type;
    int numbre_redirection;
}t_redirect;


typedef struct s_env
{
    char *key;
    char *value;
    int exported;
    struct s_env *next;
}t_env;

typedef struct s_command
{
    char **args;
    char **enve;
    t_redirect *redirect;
    t_env *env;
    struct s_command *next;
}t_command;



char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int     ft_strlen (const char *str);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
int     is_builtins (t_command *cmd);
void    execution(t_command *cmd);
void    buittin_echo (t_command *cmd);
void    extrenal_command (char *path, t_command *command);
void    built_pwd (t_command *cmd);
int     ft_atoi(const char *str);
void    builtin_exit (t_command *cmd);
int     ft_isdigit(int c);
int     ft_isalpha(int c);
char	*ft_strchr(const char *str, int c);
void    clear_pointer (char **srv);
void    export(t_command *cmd);
void    env_built (t_command *cmd);
void    free_env_list(t_env *env);
void    cd_builtin (t_command *cmd);
#endif