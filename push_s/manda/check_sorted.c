/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:29 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/10 12:11:02 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

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

void	sort_three_helper(t_node **stack_a, int first,
	int second, int third)
{
	if (first > second && second > third)
	{
		sa(stack_a, 0);
		rotate(stack_a, 0);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 0);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (first > second && second < third && first < third)
		sa(stack_a, 0);
	else if (first < second && second > third && first > third)
		rotate(stack_a, 0);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a, 0);
	else
		sort_three_helper(stack_a, first, second, third);
}

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 0);
}

void	check_sorted_range(t_node **stack_a, t_node **stack_b)
{
	if (check_sorted(*stack_a))
		return ;
	if (ft_list_size(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_list_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_list_size(*stack_a) > 3 && ft_list_size(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (ft_list_size(*stack_a) <= 100)
		intel_sort(stack_a, stack_b, 11);
	else
		intel_sort(stack_a, stack_b, 30);
}
