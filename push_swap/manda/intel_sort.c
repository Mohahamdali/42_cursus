#include "../includes/libft.h"
#include "../includes/push_swap.h"

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


int is_sorted(t_node *stack)
{
    int i;

    i = 0;
    while (stack && stack->next)
    {
        if (stack -> data > stack ->next -> data)
            i++;
        stack = stack->next;
    }
    if (i == ft_list_size(stack))
    {
        return (-1);
    }
    if ((float)i > (float)(ft_list_size(stack) / 1.03))
        return (2);
    if (i == 0)
        return (1);
    return 0;
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

void sort_array(int *array, int size, int k)
{
    int i, j, temp;


    i = 0;
    j = 0;
    while (i < size - 1)
    {
        j = 0;
        while ( j < size - i - 1)
        {
            if (k == 0 && array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            if (k == 2 && array[j] < array[j + 1])
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
    t_node *temp;
    int check;
    
    temp = (*stack_a);
    i = 0;
    size = ft_list_size (*stack_a);
    int array[size];
    while (i < size)
    {
        array[i] = temp -> data;
        i++;
        temp = temp -> next;
    }
    check = is_sorted (*stack_a);
    sort_array(array, ft_list_size(*stack_a),check);
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