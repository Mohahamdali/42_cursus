/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:16:08 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/11 17:54:12 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../includes/push_swap.h"
# include "../includes/libft.h"
# include "../includes/get_next_line_bonus.h"

void	execute_instruction(t_node **stack_a, t_node **stack_b, char *str);
void	process_instructions(t_node **stack_a, t_node **stack_b);
void	exit_error_bonus(t_node **stack_a, char *str, t_node **stack_b);

#endif