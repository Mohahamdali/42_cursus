/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:37 by mhamdali          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:49 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

extern char **environ;


char **split_command(char *command)
{
   return (ft_split(command,' '));
}

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

void  check_command (char *path, char *command)
{
   pid_t child = fork();
   int i = 0;
   char *test;
   char **src = ft_split(path,':');
   char **args = split_command(command);
   if (child == 0)
   {
      while (src[i])
      {
         char *fullpath = ft_strjoin (src[i],"/");
         test = ft_strjoin (fullpath, args[0]);
         free(fullpath);
         if (access(test,F_OK) == 0)
         {
            execve(test, args, NULL);
         }
         free(test);
         i++;
      }
      printf("command not found: %s\n",command);
      exit(1);
   }
   else
      wait(NULL);
   clear_pointer(src);
}

int main ()
{
   char *command = readline ("minichell$ ");
   char *path = getenv("PATH");
   if (path)
      check_command(path,command);
   else
      printf("PATH NOT FOUND\n");

}