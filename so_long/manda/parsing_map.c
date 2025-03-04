/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:13 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 14:57:43 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_data(int fd, t_map *map)
{
	if (!map -> data)
		exit_e(fd, map);
}

void	read_map_lines(int fd, t_map *map)
{
	int		lines;
	char	*line;

	lines = 0;
	map->data = malloc(sizeof(char *) * 100);
	check_map_data (fd, map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (lines >= 43)
		{
			free(line);
			map->data[lines - 1] = NULL;
			exit_e(fd, map);
		}
		map->data[lines] = ft_strdup(line);
		free(line);
		lines++;
		line = get_next_line(fd);
	}
	if (lines == 0)
		exit_p(fd);
	map->cols = lines;
	map->data[lines] = NULL;
	return ;
}

t_map	*lead_map(char *file_name)
{
	t_map	*map;
	int		fd;

	map = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error(map);
	map = malloc(sizeof(t_map));
	if (!map)
		exit_e(fd, map);
	read_map_lines(fd, map);
	if (!map)
		exit_e(fd, map);
	map->player = malloc(sizeof(t_player));
	if (!(map->player))
		exit_e(fd, map);
	if (check_walls(map) == 1 || check_len(fd, map) == 1
		|| check_player(map) == 1
		|| check_valid_path(map, map->player->y, map->player->x) == 1)
	{
		exit_e(fd, map);
	}
	close(fd);
	return (map);
}
