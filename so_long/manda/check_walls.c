/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:42 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/27 11:36:38 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_walls (t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map -> data[0][i + 1])
    { 
        if (map -> data[0][i] != '1' || map -> data[map -> cols - 1][i] != '1')
            return (1);
       i++;
    }
    i = 1;
    while (i < map -> cols)
    {
        int current_line = ft_strlen(map -> data[i]) - 1;
        if (map -> data[i][0] != '1' || map -> data[i][current_line - 1] != '1')
            return (1);
        i++;
    }
    return (0);
}