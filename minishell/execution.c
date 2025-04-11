#include "minishell.h"

int is_builtins (t_command *cmd)
{
    int i = 0;
    char *builtins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
    while (builtins[i])
    {
        if (ft_strncmp(cmd ->args[0],builtins[i],sizeof(builtins[i])) == 0)
            return (1);
        i++;
    }
    return (0);
}

void execution_builtins (t_command *cmd)
{
    if (!(ft_strncmp(cmd ->args[0],"echo",sizeof("echo"))))
        buittin_echo(cmd);
    if (!(ft_strncmp(cmd ->args[0],"pwd",sizeof("pwd"))))
        built_pwd(cmd);
    if (!(ft_strncmp(cmd ->args[0],"exit",sizeof("exit"))))
        builtin_exit(cmd);
}

void execution (t_command *cmd)
{
    char *path = getenv("PATH");
    if (is_builtins(cmd) == 1)
    {
        execution_builtins(cmd);
    }
    else
        extrenal_command (path,cmd);
}