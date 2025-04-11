#include "minishell.h"


void buittin_echo (t_command *cmd)
{
    int i = 1;
    int flag = 0;
    if (cmd->args[i] && strcmp(cmd->args[i], "-n") == 0)
    {
        flag = 1;
        i++;
    }
    while (cmd ->args[i])
    {
        printf("%s",cmd -> args[i]);
        i++;
    }
    if (!flag)
        printf("\n");
}

void built_pwd (t_command *cmd)
{
    if (cmd -> args[1])
    {
        printf("pwd: too many arguments\n");
        exit(1); // khasni free hna 
    }
    char *s = getcwd(NULL,0);
    printf("%s\n",s);
}


void builtin_exit (t_command *cmd)
{
    int i = 0;
    if (!cmd ->args[1])
        exit(0);
    if (!cmd -> args[1][i])
    {
        printf("minishell: exit: %s: numeric argument required",cmd ->args[1]);
        exit(255);
    }
    while (cmd -> args[1][i])
    {
        if (!ft_isdigit(cmd -> args[1][i]))
        {
            printf("minishell: exit: %s: numeric argument required",cmd ->args[1]);
            exit(255);
        }
        i++;
    }
    int status = ft_atoi(cmd ->args[1]);
    
    exit((unsigned char)status);
}