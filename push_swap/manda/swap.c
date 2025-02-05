/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:38 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/31 15:23:31 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void sa (t_node **stack_a)
{
    int temp;
    if (*stack_a && (*stack_a) ->next)
    {
        temp = (*stack_a) ->data;
        (*stack_a) ->data = (*stack_a) -> next -> data;
        (*stack_a) ->next->data = temp;
    }
    write(1,"sa\n",3);
}

void sb (t_node *stack_b)
{
    int temp;
    if (stack_b && stack_b -> next)
    {
        temp = stack_b -> data;
        stack_b  -> data = stack_b ->next ->data;
        stack_b ->next -> data = temp;
    }
    write(1,"sb\n",3);
}

void ss (t_node *stack_a,t_node *stack_b)
{
    sa(&stack_a);
    sb(stack_b);
}
