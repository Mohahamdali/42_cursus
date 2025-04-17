#include "minishell.h"



void env_built (t_command *cmd)
{
    int i = 0;
    if(cmd ->args[1])
    {
        if (cmd ->args[1][0] == '-')
            return ;
        printf("env: %s: No such file or directory\n",cmd ->args[1]);
        return ;
    }
    while(cmd ->enve[i])
    {
        printf("%s\n",cmd -> enve[i]);
        i++;
    }
}

void cd_builtin (t_command *cmd)
{
    chdir("HOME");
}