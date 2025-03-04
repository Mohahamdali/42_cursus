/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:45 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/02 15:21:04 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_len(int fd, t_map *map)
{
	int		i;
	size_t	len_row;

	i = 0;
	len_row = ft_strlen(map->data[0]);
	if (len_row >= 83)
		exit_e (fd, map);
	while (map->data[i + 1])
	{
		if (ft_strlen(map->data[i]) != len_row)
			return (1);
		i++;
	}
	if (ft_strlen(map->data[i]) != len_row - 1)
		return (1);
	map->rows = len_row;
	return (0);
}

int	check_chars(t_map *map, int i, int j, int *counts)
{
	char	c;

	c = map->data[i][j];
	if (c == 'P')
	{
		map->player->y = i;
		map->player->x = j;
		counts[0]++;
	}
	else if (c == 'C')
		counts[1]++;
	else if (c == 'E')
		counts[2]++;
	else if (c != '0' && c != '1' && c != '\n')
		return (1);
	return (0);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	counts[3];

	i = 0;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (check_chars(map, i, j, counts))
				return (1);
			j++;
		}
		i++;
	}
	if (counts[0] != 1 || counts[1] < 1 || counts[2] != 1)
		return (1);
	map->coins = counts[1];
	return (0);
}
