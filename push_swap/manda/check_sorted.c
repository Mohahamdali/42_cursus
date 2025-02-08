/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:29 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/08 15:13:33 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void free_stack(t_node *stack) 
{
    t_node *tmp;
    if (!stack)
        return ;
    while (stack) 
    {
        tmp = stack;
        stack = stack->next;
        free(tmp); 
    }
}

int	check_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// void handle_sort (t_node **stack_a)
// {
//     int size = ft_list_size (*stack_a);
//     int max = 0;
//     while (size != 0)
//     {
//         find_max_index (stack_a,&max);
//         while ((*stack_a) -> data != max)
//         {
//             (*stack_a) = (*stack_a) ->next;
//         }
//         ra(stack_a, 0);
//         size = ft_list_size (*stack_a) - 1;
//     }   
// }

void check_sorted_range (t_node **stack_a,t_node **stack_b)
{
    // if (ft_list_size (*stack_a) <= 5)
    //     handle_sort (stack_a);
    if (check_sorted (*stack_a))
        exit(0);
    if (ft_list_size(*stack_a) <= 100)
		intel_sort(stack_a, stack_b, 11);
	else
		intel_sort(stack_a, stack_b, 30);
}


