/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:10 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 14:35:23 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	move_player(int keycode, t_map *map)
{
	static int	move = 0;

	if (keycode == 53)
		exit_succsess(map);
	move_w (keycode, map, &move);
	move_a (keycode, map, &move);
	move_s (keycode, map, &move);
	move_d (keycode, map, &move);
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	move_player (keycode, map);
	draw_map (map);
	return (0);
}
