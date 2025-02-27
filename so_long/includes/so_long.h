/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:36:05 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/27 12:23:41 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"
# include "../includes/get_next_line.h"
# include "../includes/ft_printf.h"
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_info_mlx
{
	void	*mlx;
	void	*window;
}	t_info_mlx;

typedef struct s_game
{
	void	*wall_img;
	void	*floor;
	void	*player;
	void	*coins;
	void	*exit;
	int		flag;
}	t_game;

typedef struct s_map
{
	char		**data;
	int			cols;
	int			rows;
	int			coins;
	t_player	*player;
	t_info_mlx	*p;
	t_game		*game;
}	t_map;

typedef struct s_result
{
	int	found_e;
	int	collection;
}	t_result;

typedef struct s_flood
{
	t_map		*map;
	t_result	*result;
	char		**array;
}	t_flood;

t_map	*lead_map(char *file_name);
t_map	*read_map_lines(int fd, t_map *map);
int		check_walls(t_map *map);
int		check_len(t_map *map);
int		check_player(t_map *map);
void	exit_error_fd(int fd, t_map *map);
void	flood_fill(t_flood *flood, int y, int x);
void	draw_map(t_info_mlx *info, t_map *map);
void	exit_error(t_map *map);
int		key_hook(int keycode, t_map *map);
void	move_w(int keycode, t_map *map, int *move);
void	move_a(int keycode, t_map *map, int *move);
void	move_s(int keycode, t_map *map, int *move);
void	move_d(int keycode, t_map *map, int *move);
void	exit_succsess(t_map *map);
void	initialize_game(t_map *map);
void	load_images(t_info_mlx *info, t_map *map);
void	load_image_map(void *mlx, void **wall, void **floor, void **player);
void	load_image_coins(void *mlx, void **coins, void **exit);
void	check_images(t_map *map);
void	draw_map_images(t_info_mlx *info, t_map *map);
int		check_valid_path(t_map *map, int y, int x);
char	**extract_data(t_map *map);
void	exit_e (int fd,t_map *map);
void	free_mlx(t_map *map);
void	free_map_data(t_map *map);
void	free_images(t_map *map); 
#endif