#include "minishell.h"





int main (int ac, char **av)
{
   char *args[] = {"echo ", "nadi kanadi", NULL};
   execve("/bin/echo", args, NULL);
}