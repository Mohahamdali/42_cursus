/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:16:08 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/08 13:33:16 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "../includes/libft.h"
# include "../includes/get_next_line.h"

void	execute_instruction(t_node **stack_a, t_node **stack_b, char *str);
void	process_instructions(t_node **stack_a, t_node **stack_b);
#endif