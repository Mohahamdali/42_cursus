#include "../includes/libft.h"
#include "../includes/push_swap.h"

void rotate (t_node **stack)
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
}

void rrr (t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}
