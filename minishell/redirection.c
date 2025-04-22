#include "minishell.h"



int save_output_redi (t_command *cmd)
{
   int fd = open (cmd -> redirect ->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
   if (fd == -1)
      return ( perror("fd"),-1);
   int save_fd_1 = dup(1);
   if (dup2(fd,1) == -1) 
   {
      perror("Error redirecting stdout");
      return (close(fd), -1);
   }
   dup2(1, save_fd_1);
   close(fd);
   return 0;
}

int handle_input_redi (t_command *cmd)
{
   int fd = open (cmd -> redirect ->filename, O_RDONLY);
   if (fd == -1)
   {
      perror("fd");
      return -1;
   }
   int save_fd_0 = dup(0);
   if (dup2(fd,0) == -1)
   {
      perror("Error redirecting stdinput");
      close(fd);
      return (-1);
   }
   dup2(0, save_fd_0);
   close(fd);
   return 0;
}

int handle_output_redi (t_command *cmd)
{
   int fd = open(cmd -> redirect->filename,O_CREAT | O_TRUNC | O_WRONLY, 0644);
   if (fd == -1)
   {
      perror("fd");
      return -1;
   }
   int save_fd_1 = dup(1);
   if (dup2(fd,1) == -1) 
   {
      perror("Error redirecting stdout");
      close(fd);
      return -1;
   }
   dup2(1, save_fd_1);
   close(fd);
   return 0;
}

void apply_redirections (t_command *cmd)
{
   int i = 0;
   int result;
   cmd -> redirect = malloc (sizeof(t_redirect) * 2);
   if (!cmd ->redirect)
      return ;
   cmd ->redirect ->filename = cmd ->args[3];
   cmd -> redirect ->type = 2; // for type 1 for  ">" sf type 2 for "<" type 3 for ">>"
   
   while (cmd ->redirect[i].filename)
   {
      if (cmd -> redirect[i].type == 1) 
      {
         result = handle_output_redi(cmd);
         if (result == -1)
            return ;
      }
      if (cmd ->redirect[i].type == 2)
      {
         result = handle_input_redi(cmd);
         if (result == -1)
            return ;
      }
      if (cmd ->redirect[i].type == 3)
      {
         result = save_output_redi(cmd);
         if (result == -1)
            return ;
      }
   i++;

   }
}