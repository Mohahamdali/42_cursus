/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:17 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/08 17:17:01 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"


void exit_error_bonus (t_node **stack_a,char *str)
{
	free(str);
	free_stack (*stack_a);
	write (1,"Error\n",6);
	exit(1);
}

void	execute_instruction(t_node **stack_a, t_node **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen("sa\n")) == 0)
		sa(stack_a, 1);
	else if (ft_strncmp(str, "sb\n", ft_strlen("sb\n")) == 0)
		sb(stack_b, 1);
	else if (ft_strncmp(str, "ss\n", ft_strlen("ss\n")) == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "pa\n", ft_strlen("pa\n")) == 0)
		pa(stack_b, stack_a, 1);
	else if (ft_strncmp(str, "pb\n", ft_strlen("pb\n")) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "ra\n", ft_strlen("ra\n")) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(str, "rb\n", ft_strlen("rb\n")) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(str, "rr\n", ft_strlen("rr\n")) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "rra\n", ft_strlen("rra\n")) == 0)
		rotate(stack_a, 3);
	else if (ft_strncmp(str, "rrb\n", ft_strlen("rrb\n")) == 0)
		rotate(stack_b, 3);
	else if (ft_strncmp(str, "rrr\n", ft_strlen("rrr\n")) == 0)
		rrr(stack_a, stack_b, 0);
	else
		exit_error_bonus(stack_a,str);
}
