/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:33 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/29 16:25:41 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void pa (t_node **stack_a,t_node **stack_b)
{
    int value;
    if(*stack_b)
    {
        value = pop(stack_b);
        push_front(stack_a,value);
    }
}

void pb (t_node **stack_a, t_node **stack_b)
{
    int value;
    if(*stack_a)
    {
        value = pop(stack_a);
        push_front(stack_b, value);
    }

}