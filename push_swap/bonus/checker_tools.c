#include "checker.h"
#include "../includes/libft.h"
#include "../includes/push_swap.h"

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
            exit_error();
        str++;
    }
    return (1);
}


int main ()
{
    t_node *p1 = create_node (133);
    t_node *p2 = create_node (2);
    t_node *p3 = create_node (3);
    t_node *p4 = create_node (4);

    p1 ->next = p2;
    p2 -> next = p3;
    p3 -> next = p4;

    if (is_sorted (p1))
        printf("ok");
    else
        printf("ko");
}