/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:37 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/18 09:55:56 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void clear_pointer(char **srv)
{
    if (srv == NULL)
        return;

    int i = 0;
    while (srv[i])
    {
        free(srv[i]);
        srv[i] = NULL;
        i++;
    }
    free(srv);
}


void  extrenal_command (char *path, t_command *command)
{
   pid_t child = fork();
   int i = 0;
   char *test;
   char **src = ft_split(path,':');

   if (child == 0)
   {
      while (src[i])
      {
         char *fullpath = ft_strjoin (src[i],"/");
         test = ft_strjoin (fullpath, command ->args[0]);
         free(fullpath);
         if (access(test,F_OK) == 0)
            execve(test, command ->args, NULL);
         free(test);
         i++;
      }
      printf("command not found: %s\n",command ->args[0]);
      exit(1);
   }
   else
      waitpid(-1,NULL,0);
   clear_pointer(src);
}

int main (int ac, char **argv ,char **ergenv)
{
   t_command *command = malloc(sizeof(t_command));
   command ->enve = ergenv;
   command ->args = malloc(sizeof(char *) * 4);
   command ->args[0] = "ls";
   command ->args[1] = NULL;
   command ->args[2] = "<";
   command ->args[3] = "nadi";
   command ->args[4] = NULL;
   execution(command);
   // command ->args[0] = "export";
   // command ->args[1] = NULL;
   // command ->args[2] = NULL;
   // execution(command);
}