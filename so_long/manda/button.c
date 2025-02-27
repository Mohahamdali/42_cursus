/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:28:27 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/26 13:46:01 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(int keycode, t_map *map, int *move)
{
	if (keycode == 13 && map->data[map->player->y - 1][map->player->x] != '1')
	{
		if (map->data[map->player->y - 1][map->player->x] == 'E')
		{
			if (map->coins == 0)
				exit_succsess(map);
			return ;
		}
		if (map->data[map->player->y - 1][map->player->x] == 'C')
			map->coins--;
		map->data[map->player->y--][map->player->x] = '0';
		map->data[map->player->y][map->player->x] = 'P';
		(*move)++;
		ft_printf("Move: %d\n", *move);
	}
}

void	move_a(int keycode, t_map *map, int *move)
{
	if (keycode == 0 && map->data[map->player->y][map->player->x - 1] != '1')
	{
		if (map->data[map->player->y][map->player->x - 1] == 'E')
		{
			if (map->coins == 0)
				exit_succsess(map);
			return ;
		}
		if (map->data[map->player->y][map->player->x - 1] == 'C')
			map->coins--;
		map->data[map->player->y][map->player->x--] = '0';
		map->data[map->player->y][map->player->x] = 'P';
		(*move)++;
		ft_printf("Move: %d\n", *move);
	}
}

void	move_s(int keycode, t_map *map, int *move)
{
	if (keycode == 1 && map->data[map->player->y + 1][map->player->x] != '1')
	{
		if (map->data[map->player->y + 1][map->player->x] == 'E')
		{
			if (map->coins == 0)
				exit_succsess(map);
			return ;
		}
		if (map->data[map->player->y + 1][map->player->x] == 'C')
			map->coins--;
		map->data[map->player->y++][map->player->x] = '0';
		map->data[map->player->y][map->player->x] = 'P';
		(*move)++;
		ft_printf("Move: %d\n", *move);
	}
}

void	move_d(int keycode, t_map *map, int *move)
{
	if (keycode == 2 && map->data[map->player->y][map->player->x + 1] != '1')
	{
		if (map->data[map->player->y][map->player->x + 1] == 'E')
		{
			if (map->coins == 0)
				exit_succsess(map);
			return ;
		}
		if (map->data[map->player->y][map->player->x + 1] == 'C')
			map->coins--;
		map->data[map->player->y][map->player->x++] = '0';
		map->data[map->player->y][map->player->x] = 'P';
		(*move)++;
		ft_printf("Move: %d\n", *move);
	}
}
