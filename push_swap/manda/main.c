/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:17 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/31 19:56:46 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>



void f()
{
    system ("leaks push_swap");
}
int main (int ac,char **av)
{
    int a = 1;
    if (ac < 2)
        return (0);
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    while(av[a])
    {
        check_valid_numbre(av[a]);
        push_back(&stack_a,ft_atoi(av[a]));
        a++;
    }
    check_numbre(stack_a);
    quick_sort (&stack_a, &stack_b,ft_list_size(stack_a),1);
    print_list (stack_a);
}
