/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:02 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/06 10:52:41 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"


void ra (t_node **stack_a)
{
    t_node *first;
    t_node *last;
    if (*stack_a && (*stack_a) -> next)
    {
        first = *stack_a;
        last = *stack_a;
        while (last ->next)
        {
            last = last -> next;
        }
        *stack_a = first -> next;
        first -> next = NULL;
        last -> next = first;
    }
    write(1,"ra\n",3);
}

void  rb (t_node **stack_b)
{
    t_node *first;
    t_node *last;
    if (*stack_b && (*stack_b) -> next)
    {
        first = *stack_b;
        last  = *stack_b;
        while (last -> next)
            last = last -> next;
        *stack_b = (*stack_b) -> next;
        first -> next = NULL;
        last -> next = first;
    }
    write(1,"rb\n",3);
}

void rr (t_node **stack_a,t_node **stack_b)
{
    ra (stack_a);
    rb (stack_b);
    write(1,"rr\n",3);
}