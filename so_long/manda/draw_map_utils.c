/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:46:08 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/02 15:12:02 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_game(t_map *map)
{
	if (!map->game)
	{
		map->game = malloc(sizeof(t_game));
		if (!map->game)
		{
			exit_error(map);
		}
		map->game->flag = 0;
	}
	if (!map->data)
		exit_error(map);
}

void	load_images(t_info_mlx *info, t_map *map)
{
	if (!map->game->flag)
	{
		load_image_map(info->mlx, &map->game->wall_img,
			&map->game->floor, &map->game->player);
		load_image_coins(info->mlx, &map->game->coins, &map->game->exit);
		map->game->flag = 1;
		return ;
	}
}

void	check_images(t_map *map)
{
	if (!(map->game->wall_img) || !(map->game->floor)
		|| !(map->game->player) || !(map->game->coins)
		|| !(map->game->exit))
		exit_error(map);
}

void	put_image(t_info_mlx *info, void *img, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->window,
		img, x * 32, y * 32);
}

void	draw_map_images(t_info_mlx *info, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->cols)
	{
		x = 0;
		while (x < map->rows)
		{
			put_image(info, map->game->floor, x, y);
			if (map->data[y][x] == '1')
				put_image(info, map->game->wall_img, x, y);
			else if (map->data[y][x] == 'P')
				put_image(info, map->game->player, x, y);
			else if (map->data[y][x] == 'C')
				put_image(info, map->game->coins, x, y);
			else if (map->data[y][x] == 'E')
				put_image(info, map->game->exit, x, y);
			x++;
		}
		y++;
	}
}
