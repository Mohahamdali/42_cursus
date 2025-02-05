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


int find_max_index (t_node **stack_a,int *max)
{
    int index;
    t_node *temp;

    index = 0;
    temp = *stack_a;
    *max = temp -> data;
    while (temp)
    {
        if (*max < temp -> data)
            *max = temp -> data;
       temp = temp -> next;
    }
    temp = (*stack_a);
    while (temp)
    {
        if (temp -> data == *max)
            return (index);
        index++;
        temp = temp ->next;
    }
    return (index);
}

void sort_array(int *array, int size)
{
    int i, j, temp;


    i = 0;
    j = 0;
    while (i < size - 1)
    {
        j = 0;
        while ( j < size - i - 1)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void index_nodes (t_node **stack_a)
{
    int i;
    int size;

    t_node *temp = (*stack_a);
    i = 0;
    size = ft_list_size (*stack_a);
    int array[size];
    while (i < size)
    {
        array[i] = temp -> data;
        i++;
        temp = temp -> next;
    }
    sort_array(array, ft_list_size(*stack_a));
    i = 0;
    while (i < size)
    { 
        temp = (*stack_a);
        while (temp)
        {
            if (array[i] == temp ->data)
                temp -> index = i;
             temp = temp -> next;
        }
        i++;
    }
}

void intel_sort (t_node **stack_a,t_node **stack_b,int range)
{
    int size;
    int index_max;
    int max;

    size = ft_list_size (*stack_a);
    index_nodes (stack_a);
    while (size != 0)
    {
        if ((*stack_a) -> index <= ft_list_size(*stack_b))
            pb (stack_a,stack_b);
        else if ((*stack_a) -> index < ft_list_size(*stack_b) + range)
        {
            pb(stack_a,stack_b);
            rb(stack_b);
        }
        else
            ra(stack_a);
        size = ft_list_size(*stack_a);
    } 
    size = ft_list_size(*stack_b);
    while (size)
    {
        index_max = find_max_index (stack_b,&max);
        if (index_max <  size / 2)
        {
            while((*stack_b) -> data != max)
                rb(stack_b);
            pa(stack_b,stack_a);
        }
        else
        {
            while ((*stack_b) -> data != max)
                rotate (stack_b,1);
            pa(stack_b, stack_a);
        }
       size = ft_list_size(*stack_b);
    }
}