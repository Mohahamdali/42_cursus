/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:57:41 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 19:06:49 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void find_min_index_push(t_node **stack, t_node **stack_b)
{
    int min = (*stack)->data;
    int min_index = 0;
    int index = 0;
    t_node *current = *stack;
    while (current != NULL)
    {
        if (current -> data <= min)
        {
            min = current->data;
            min_index = index;
        }
        index++;
        current = current -> next;
    }
    while (min_index > ft_list_size(*stack) / 2 && (*stack) -> data != min)
    {
        rotate(stack, 0);
    }
    while (min_index <= ft_list_size(*stack) / 2 && (*stack) -> data != min)
    {
        ra(stack, 0);
    } 
    pb (stack, stack_b,0);
}

void sort_five (t_node **stack_a, t_node **stack_b)
{
    find_min_index_push (stack_a, stack_b);
    if (ft_list_size (*stack_a) == 4)
        find_min_index_push (stack_a, stack_b);
    sort_three (stack_a);
    while (*stack_b)
    {
        pa(stack_b,stack_a,0);
    }
}