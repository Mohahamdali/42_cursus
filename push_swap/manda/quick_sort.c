#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>

int ft_list_size(t_node *begin_list)
{
    int i;
    t_node *temp;
    temp = begin_list;

    i = 0;
    while (temp)
    {
       temp  = temp->next;
        i++;
    }
    return (i);
}

int choose_pivot (t_node **stack_a)
{
    if (!stack_a || !*stack_a)
        return (0);
    return ((*stack_a) -> data);
}

void quick_sort (t_node **stack_a, t_node **stack_b, int size)
{
    int pivot;
    int i;
    
    i = 0;
    pivot = choose_pivot (stack_a);
    if (size <= 1)
        return ;
    if (size == 2)
    {
        if ((*stack_a) -> data > (*stack_a) -> next-> data)
            sa(stack_a);
        return ;
    }
    
    while (i < size)
    {
        if ((*stack_a) -> data < pivot)
        {
            pb (stack_a, stack_b);
            i++;
        }
        else
        {
            ra(stack_a);
        }
    }
    quick_sort (stack_a, stack_b, size - i);
    quick_sort (stack_b, stack_a, i);
    while (*stack_b)
    {
        pa (stack_b, stack_a);
    }
}
