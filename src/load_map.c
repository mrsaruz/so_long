/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:25:40 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 17:27:36 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Cuenta los elementos importantes(C, P, E) del mapa
void	count_map_elements(t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	map->exit = 0;
	map->collectibles = 0;
	i = 0;
	while (i < map->height) // Recorremos cada fila del mapa
	{
		j = 0;
		while (map->grid[i][j]) // Recorremos cada columna de la fila actual
		{
			if (map->grid[i][j] == 'P')
				map->player++; // Contamos jugadores, debe ser 1
			else if (map->grid[i][j] == 'E')
				map->exit++; // Contamos salidas, debe ser 1
			else if (map->grid[i][j] == 'C')
				map->collectibles++; // Contamos coleccionables
			j++;
		}
		i++;
	}
}

// Función auxiliar para validar el mapa cargado
static int	validate_loaded_map(t_map *map)
{
	count_map_elements(map);
	find_player_position(map);
	if (!validate_map(map))
	{
		free_map_grid(map->grid, map->height);
		return (0);
	}
	return (1);
}

// Función principal que coordina la carga completa del mapa
int	load_map(char *filename, t_map *map)
{
	map->height = count_map_lines(filename); // Calculamos altura del mapa leyendo el archivo
	if (map->height <= 0)
	{
		ft_printf("Error: Failed to calculate map height.\n");
		return (0);
	}
	map->grid = allocate_map_grid(map->height); // Asignamos memoria para la matriz
	if (!map->grid)
		return (0);
	if (!fill_map_grid(filename, map->grid, map->height)) // Llenamos la matriz con los datos del archivo
	{
		ft_printf("Error: Failed to fill map grid.\n");
		free(map->grid); // Liberamos memoria en caso de error
		return (0);
	}
	map->width = ft_strlen(map->grid[0]); // Calculamos el ancho del mapa (longitud de la primera línea)
	return (validate_loaded_map(map)); // El mapa se cargó y validó correctamente
}
