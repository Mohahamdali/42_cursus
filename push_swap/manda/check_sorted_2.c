#include "../includes/libft.h"
#include "../includes/push_swap.h"

int find_min_index_push(t_node **stack, t_node **stack_b)
{
    int min = (*stack)->data;
    int min_index = 0;
    int index = 0;
    t_node *current = *stack;
    while (current != NULL)
    {
        if (current -> data < min)
        {
            min = current->data;
            min_index = index;
        }
        index++;
        current = current -> next;
    }
    return (min_index);
    while (min_index > 0)
    {
        ra(stack,0);
        min_index --;
    }
    pb (stack, stack_b,0);
}

// void sort_five (t_node **stack_a, t_node **stack_b)
// {
//     find_min_index_push (stack_a, stack_b);
//     find_min_index_push (stack_a, stack_b);
//     sort_three (stack_a);
//     while (*stack_b)
//     {
//         pa(stack_a,stack_b,0);
//         if ((*stack_a) -> data > (*stack_a) -> next -> data)
//         {
//             ra(stack_a, 0);
//         }
//     }
// }