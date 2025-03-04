/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:22 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 11:56:58 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**extract_data(t_map *map)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * (map->cols + 1));
	if (!array)
		return (NULL);
	while (i < map->cols)
	{
		array[i] = malloc(sizeof(char) * (map->rows + 1));
		j = 0;
		while (map->data[i][j] != '\0')
		{
			array[i][j] = map->data[i][j];
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	flood_fill(t_flood *flood, int y, int x)
{
	if (!flood->map || !flood->map->data || flood->map->rows <= 0
		|| flood->map->cols <= 0)
		return ;
	if (x < 0 || y < 0 || y >= flood->map->cols || x >= flood->map->rows)
		return ;
	if (flood->array[y][x] == '1' || flood->array[y][x] == 'a')
		return ;
	if (flood->array[y][x] == 'E')
	{
		flood->result->found_e = 1;
		if (flood->result->collection < flood->map->coins)
			return ;
	}
	if (flood->array[y][x] == 'C')
		flood->result->collection++;
	flood->array[y][x] = 'a';
	flood_fill(flood, y + 1, x);
	flood_fill(flood, y - 1, x);
	flood_fill(flood, y, x + 1);
	flood_fill(flood, y, x - 1);
}

int	check_valid_path(t_map *map, int start_y, int start_x)
{
	char		**array;
	t_result	collectible_check;
	t_flood		flood;

	collectible_check.collection = 0;
	collectible_check.found_e = 0;
	array = extract_data(map);
	if (!array)
		return (1);
	flood.map = map;
	flood.result = &collectible_check;
	flood.array = array;
	flood_fill(&flood, start_y, start_x);
	free_array(array, map ->cols);
	if (collectible_check.collection == map->coins && collectible_check.found_e)
		return (0);
	return (1);
}
