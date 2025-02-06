#include "../includes/get_next_line.h"
#include "checker.h"
#include <libc.h>

void exit_error (void)
{
    write(2,"Error\n",6);
    exit(1);
}