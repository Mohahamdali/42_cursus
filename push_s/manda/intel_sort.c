/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:33 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/10 12:15:21 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	find_max_index(t_node **stack_a, int *max)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = *stack_a;
	*max = temp->data;
	while (temp)
	{
		if (*max < temp->data)
			*max = temp->data;
		temp = temp->next;
	}
	temp = (*stack_a);
	while (temp)
	{
		if (temp->data == *max)
			return (index);
		index++;
		temp = temp->next;
	}
	return (index);
}

void	index_nodes(t_node **stack_a)
{
	int		i;
	int		size;
	int		check;
	int		*array;
	t_node	*temp;

	i = 0;
	size = ft_list_size(*stack_a);
	array = extract_stack_data(*stack_a, size);
	check = is_sorted(*stack_a);
	sort_array(array, ft_list_size(*stack_a), check);
	i = -1;
	while (++i < size)
	{
		temp = (*stack_a);
		while (temp)
		{
			if (array[i] == temp->data)
				temp->index = i;
			temp = temp->next;
		}
	}
	free(array);
}

void	process_max_value(t_node **stack_a, t_node **stack_b,
	int index_max, int max)
{
	if (index_max < ft_list_size(*stack_b) / 2)
	{
		while ((*stack_b)->data != max)
			rb(stack_b, 0);
	}
	else
	{
		while ((*stack_b)->data != max)
			rotate(stack_b, 1);
	}
	pa(stack_b, stack_a, 0);
}

void	sort_back(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	index_max;
	int	max;

	size = ft_list_size(*stack_b);
	while (size)
	{
		index_max = find_max_index(stack_b, &max);
		process_max_value(stack_a, stack_b, index_max, max);
		size = ft_list_size(*stack_b);
	}
}

void	intel_sort(t_node **stack_a, t_node **stack_b, int range)
{
	int	size;

	size = ft_list_size(*stack_a);
	index_nodes(stack_a);
	while (size != 0)
	{
		if ((*stack_a)->index <= ft_list_size(*stack_b))
			pb(stack_a, stack_b, 0);
		else if ((*stack_a)->index < ft_list_size(*stack_b) + range)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
		}
		else
			ra(stack_a, 0);
		size = ft_list_size(*stack_a);
	}
	sort_back(stack_a, stack_b);
}
