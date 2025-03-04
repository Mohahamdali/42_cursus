/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:40 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 15:02:05 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_map *map)
{
	if (map->game)
	{
		if (map->p && map->p->mlx)
		{
			if (map->game->wall_img)
				mlx_destroy_image(map->p->mlx, map->game->wall_img);
			if (map->game->floor)
				mlx_destroy_image(map->p->mlx, map->game->floor);
			if (map->game->player)
				mlx_destroy_image(map->p->mlx, map->game->player);
			if (map->game->coins)
				mlx_destroy_image(map->p->mlx, map->game->coins);
			if (map->game->exit)
				mlx_destroy_image(map->p->mlx, map->game->exit);
		}
		free(map->game);
	}
}

void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL || map->data == NULL)
		return ;
	while (map->data[i])
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

void	free_mlx(t_map *map)
{
	if (map->p)
	{
		if (map->p->mlx && map->p->window)
			mlx_destroy_window(map->p->mlx, map->p->window);
		if (map->p->mlx)
			free(map->p->mlx);
		free(map->p);
	}
}

void	free_all(t_map *map)
{
	if (!map)
		return ;
	free_map_data(map);
	if (map->player)
		free(map->player);
	free_images(map);
	free_mlx(map);
	free(map);
}

void	exit_error(t_map *map)
{
	free_all(map);
	ft_putstr_fd("Error\ninvalid map needs\n", 2);
	exit(1);
}
