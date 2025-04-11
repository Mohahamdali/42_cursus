/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:37 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/11 15:56:19 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void clear_pointer (char **srv)
{
   int i;

   i = 0;
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

int main ()
{
   t_command *command = malloc(sizeof(t_command));
   command ->args = malloc(sizeof(char *) * 4);
   command ->args[0] = "exit";
   command ->args[1] = "";
   command ->args[2] = NULL;
   execution(command);
}