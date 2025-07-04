/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/04 15:27:55 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(char *filename, t_map *map)
{
	map->height = count_map_height(filename);
	if (map->height <= 0)
	{
		ft_printf("Error: Failed to calculate map height.\n");
		return (0);
	}
	map->grid = allocate_map_grid(map->height);
	if (!map->grid)
		return (0);
	if (!fill_map_grid(filename, map->grid, map->height))
	{
		ft_printf("Error: Failed to fill map grid.\n");
		free(map->grid);
		return (0);
	}
	map->width = ft_strlen(map->grid[0]);
	count_map_elements(map);
	if (!validate_player_count(map) || !validate_collectibles(map)
		|| !validate_exit_count(map) || !validate_map_walls(map))
		return (0);
	return (1);
}
