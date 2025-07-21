/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:46:55 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/21 18:20:24 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Crear copia del mapa
static char ** copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while(--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

// Liberar copia del mapa
static void	free_map_copy(char **map_copy, int height)
{
	int i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

// flood_fill
static void	flood_fill(char **map_copy, t_coords *coords)
{
	if (coords->x < 0 || coords->x >= coords->width 
		|| coords->y < 0 || coords->y >= coords->height)
		return ;
	if (map_copy[coords->y][coords->x] == '1' 
		|| map_copy[coords->y][coords->x] == 'F')
		return ;
	map_copy[coords->y][coords->x] = 'F';
	coords->x += 1;
	flood_fill(map_copy, coords);
	coords->x -= 2;
	flood_fill(map_copy, coords);
	coords->x += 1;
	coords->y += 1;
	flood_fill(map_copy, coords);
	coords->y -= 2;
	flood_fill(map_copy, coords);
	coords->y += 1;
}

// Validar que todos los elementos son alcanzables, hay un camino válido
int	validate_path(t_map *map)
{
	char		**map_copy;
	t_coords	coords;
	int			i;
	int			j;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	coords.x = map->player_x;
	coords.y = map->player_y;
	coords.width = map->width;
	coords.height = map->height;
	flood_fill(map_copy, &coords);
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map_copy(map_copy, map->height);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map_copy(map_copy, map->height);
	return (1);
}

