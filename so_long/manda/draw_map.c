/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:33:38 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/27 10:42:50 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image_map(void *mlx, void **wall, void **floor, void **player)
{
	int	width;
	int	height;

	*wall = mlx_xpm_file_to_image(mlx, "textures/tree.xpm", &width, &height);
	*floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &width, &height);
	*player = mlx_xpm_file_to_image(
        mlx, "textures/fenandjeck.xpm", &width, &height);
	if (!(*wall) || !(*floor) || !(*player))
		return ;
}

void	load_image_coins(void *mlx, void **coins, void **exit)
{
	int	width;
	int	height;

	*coins = mlx_xpm_file_to_image(
        mlx, "textures/Webp.net-resizeimage.xpm", &width, &height);
	*exit = mlx_xpm_file_to_image(mlx, "textures/bab.xpm", &width, &height);
	if (!(*coins) || !(*exit))
		return ;
}

void	draw_map(t_info_mlx *info, t_map *map)
{
	initialize_game(map);
	load_images(map->p, map);
	check_images(map);
	draw_map_images(map->p, map);
}
