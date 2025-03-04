/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:17 by mhamdali          #+#    #+#             */
/*   Updated: 2025/03/04 14:56:18 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	close_window(t_map *map)
{
	exit_succsess(map);
	return (0);
}

void f()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_map	*map;
	atexit(f);
	if (ac != 2)
		return (write(2, "Error\n", 6), 0);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		return (write(2, "Error\n", 6), 0);
	map = lead_map(av[1]);
	if (!map)
		return (ft_putstr_fd("Error\nthis not valid\n", 2), 1);
	map->p = malloc(sizeof(t_info_mlx));
	if (!map->p)
		exit_error(map);
	map->game = NULL;
	map->p->mlx = mlx_init();
	if (!(map->p->mlx))
		exit_error(map);
	map->p->window = mlx_new_window(map->p->mlx, (map->rows - 1) * 32,
			map->cols * 32, "so_long game");
	if (!(map->p->window))
		exit_error(map);
	draw_map(map);
	mlx_hook(map->p->window, 17, 0, close_window, map);
	mlx_hook(map->p->window, 2, 1L, key_hook, map);
	mlx_loop(map->p->mlx);
	exit_succsess(map);
}
