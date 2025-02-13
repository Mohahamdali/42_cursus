/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:19:40 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/10 13:36:54 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	is_sorted(t_node *stack)
{
	int		i;
	float	j;

	i = 0;
	j = ft_list_size(stack);
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			i++;
		stack = stack->next;
	}
	if ((float)i > (float)(j / 1.5))
		return (2);
	if (i == 0)
		return (1);
	return (0);
}

int	*extract_stack_data(t_node *stack, int size)
{
	int		*array;
	int		i;
	t_node	*temp;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	temp = stack;
	i = 0;
	while (i < size)
	{
		array[i] = temp->data;
		i++;
		temp = temp->next;
	}
	return (array);
}

void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_list_size(t_node *begin_list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_array(int *array, int size, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (k == 2 && array[j] > array[j + 1])
				swap_array(&array[j], &array[j + 1]);
			if (k == 2 && array[j] < array[j + 1])
				swap_array(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}
