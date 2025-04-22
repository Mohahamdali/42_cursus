/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:12:39 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/17 15:11:12 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (!(ft_strncmp(cmd ->args[0],"export",sizeof("export"))))
        export(cmd);
    if (!(ft_strncmp(cmd ->args[0],"env",sizeof("env"))))
        env_built(cmd);
    if (!(ft_strncmp(cmd ->args[0],"cd",sizeof("cd"))))
        cd_builtin(cmd);
}

void execution (t_command *cmd)
{
    int a = 1;
    char *path = getenv("PATH");
    if (a)
        apply_redirections(cmd);
    if (is_builtins(cmd) == 1)
        execution_builtins(cmd);
    else
        extrenal_command (path, cmd);
}