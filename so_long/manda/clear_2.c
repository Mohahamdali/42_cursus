/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:15:12 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 14:19:52 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_succsess(t_map *map)
{
	free_all(map);
	exit(0);
}

void	free_array(char **array, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_e(int fd, t_map *map)
{
	map ->p = NULL;
	map -> game = NULL;
	free_all(map);
	close(fd);
	ft_putstr_fd("Error\ninvalid map needs\n", 2);
	exit(1);
}

void	exit_p(int fd)
{
	close(fd);
	ft_putstr_fd("Error\ninvalid map needs\n", 2);
	exit(1);
}
