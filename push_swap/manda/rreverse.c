#include "../includes/libft.h"
#include "../includes/push_swap.h"

void rotate (t_node **stack, int n)
{
    t_node *second_first;
    t_node *last;
    if(*stack && (*stack) -> next)
    {
        last = *stack;
        while (last -> next)
        {
            second_first = last;
            last = last -> next;
        }
        last -> next = *stack;
        second_first -> next = NULL;
        *stack = last;
    }
    if (n == 0)
        write(1,"rra\n",4);
    else if (n == 1)
    {
        write(1,"rrb\n",4);
    }
}

void rrr (t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a,2);
    rotate(stack_b,2);
}
