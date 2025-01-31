#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>

int ft_list_size(t_node *begin_list)
{
    int i = 0;
    t_node *temp = begin_list;

    while (temp)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void sort_three(int *first, int *middle, int *last)
{
    int a = *first;
    int b = *middle;
    int c = *last;

    if ((a > b && a < c) || (a > c && a < b))
        *middle = a;
    else if ((b > a && b < c) || (b > c && b < a))
        *middle = b;
    else
        *middle = c;
}

int choose_pivot(t_node **stack_a)
{
    int count;
    int i = 0;
    t_node *first = *stack_a;
    t_node *mide = *stack_a;
    t_node *last = *stack_a;
    
    i = 0;
    if (!stack_a || !*stack_a || !(*stack_a) -> next)
        return 0;
    count = ft_list_size (*stack_a);
    while (last -> next)
        last = last -> next;
    
    while (i < count / 2 )
    {
        mide = mide -> next;
        i++;
    }
    int first_1 = first -> data;
    int last_2 = last -> data;
    int mid_3 = mide -> data;
    sort_three(&first_1, &mid_3,&last_2);
    return (mid_3);
   
}


void quick_sort (t_node **stack_a, t_node **stack_b, int size,int check)
{
    int pivot;
    int i;
    
    i = 0;
    int move = 0;
    pivot = choose_pivot (stack_a);
   
    if (size < 1 || !stack_a || !*stack_a)
        return;
    if (size == 2 && check == 1)
    {
        if ((*stack_a) -> data > (*stack_a) -> next-> data)
            sa(stack_a);
        return ;
    }
    // printf("pivot: %d\n",pivot);
    while (i < size)
    {
        if (((*stack_a) -> data < pivot))
        {
            pb(stack_a, stack_b);
            move++;
        }
        else
            ra(stack_a);
            i++;
    } 
   
    if (move > 0)
    {
        quick_sort(stack_a, stack_b, size - move, 0);
        quick_sort(stack_b, stack_a, move, 0);
    }
   
     while (*stack_b)
    {
        if (ft_list_size (*stack_b) == 2)
        {
            if ((*stack_b)-> data < (*stack_b) ->next -> data)
                sb(*stack_b);
        }
        pa (stack_b, stack_a);
    }
}
