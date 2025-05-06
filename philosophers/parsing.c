#include "philosopher.h"

void    check_valid_numbre (char *str)
{
    if (*str == '\0')
    {
        write(2,"Error\n",6);
        exit(1);
    }
    if (*str == '+')
        str++;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
        {
            write(2,"Error\n",6);
            exit(1);
        }
        str++;
    }
}