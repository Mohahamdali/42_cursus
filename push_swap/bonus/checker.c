/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:16:22 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/08 15:45:06 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	split_argument(char *str, t_node **stack_a)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	if (*str == '\0')
		exit_error(0, *stack_a,&split);
	split = ft_split(str, ' ');
	if (!split)
		return ;
	while (split[i])
	{
		check_valid_number(split[i], *stack_a, &split);
		push_back(stack_a, ft_atoi(split[i],*stack_a,&split));
		free(split[i]);
		i++;
	}
	if (i == 0)
		exit_error(0,*stack_a,&split);
	free(split);
}

void	process_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	int		a;
	t_node	*stack_a;
	t_node	*stack_b;

	a = 1;
	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (av[a])
	{
		split_argument(av[a], &stack_a);
		a++;
	}
	check_duplicate(stack_a);
	process_instructions(&stack_a, &stack_b);
	if (check_sorted(stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
