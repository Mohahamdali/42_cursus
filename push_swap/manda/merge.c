#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>



void merge(t_node **stack_a, t_node **stack_b) {
    while (*stack_b) {
        if (!*stack_a || (*stack_b)->data <= (*stack_a)->data) {
            pa(stack_a, stack_b);
        } else {
            ra(stack_a);
        }
    }

    while ((*stack_a)->next && (*stack_a)->data > (*stack_a)->next->data) {
        ra(stack_a);
    }
}


void merge_sort_1(t_node **stack_a, t_node **stack_b, int size) {
    if (size <= 1)
        return;

    int mid = size / 2;

    for (int i = 0; i < mid; i++) 
    {
        pb(stack_a, stack_b);
    }

  
    merge_sort_1(stack_a, stack_b, size - mid);

    
    merge_sort_1(stack_b, stack_a, mid);


    merge(stack_a, stack_b);
}
