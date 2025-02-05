/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:33 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/30 13:45:49 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void pa(t_node **stack_b, t_node **stack_a)
{
    if (*stack_b == NULL)
        return;

    t_node *temp = *stack_b; 
    *stack_b = (*stack_b)->next; 
    temp->next = *stack_a;
    *stack_a = temp;
    write(1,"pa\n",3);
}
void pb (t_node **stack_a, t_node **stack_b)
{
    int value;
    if(*stack_a)
    {
        value = pop(stack_a);
        push_front(stack_b, value);
    }
    write(1,"pb\n",3);
}