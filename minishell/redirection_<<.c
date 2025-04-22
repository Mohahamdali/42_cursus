#include "minishell.h"


void handle_heredoc (t_command *cmd)
{
    int nread = 0;
    char buffer[40303];
    while (1)
    {
        nread = read (1,buffer,1);
        if (ft_strncmp(buffer))
    }
}