#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>

void check_numbre (t_node *head)
{
    t_node *temp;
    t_node *first = head;
    while (first)
    {
        temp = first -> next;
        while (temp)
        {
            
            if (first ->data == temp ->data)
            {
                ft_putstr_fd("Error",2);
                exit(1);
            }
            temp = temp -> next;
            
        }
        first = first -> next;
    }
  
}

int check_valid_numbre (char *str)
{
    while (*str == ' ')
        str++;
    if (*str == '\0')
    {
        ft_putstr_fd ("Error",2);
        exit(1);
    }
    if (*str == '+' || *str == '-')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
        {
            ft_putstr_fd ("Error", 2);
            exit (1);
        }
        str++;
    }
    return (1);
}

void check_numbre_overflow (long n,int sign)
{
    if (sign == -1)
        n = n * -1;
    if (n >  INT_MAX || n < INT_MIN)
    {
        ft_putstr_fd ("Error", 2);
        exit (1);
    }
}
