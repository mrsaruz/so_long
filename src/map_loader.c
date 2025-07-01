/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/01 12:49:17 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(char *filename, t_map *map)
{
	map->height = count_map_height(filename); // Calculamos la atura del mapa
	if(map->height <= 0)
	{
		ft_printf("Error: Failed to calculate map height.\n");
		return (0);
	}
	map->grid = allocate_map_grid(map->height); // asigna memroria para la matriz del mapa (grid)
	if(!map->grid)
		return (0);
	// Llena la matriz del mapa con las líneas del archivo
	if (!fill_map_grid(filename, map->grid, map->height))
	{
		ft_printf("Error: Failed to fill map grid.\n");
		free(map->grid); // libera memoria si ocurre un error
		return (0);
	}
	map->width = ft_strlen(map->grid[0]); // Calcula el ancho del mapa usando la primera línea
	count_map_elements(map); // Cuenta los elementos importantes del mapa (C, P, E)
	if (!validate_map_walls(map)) // Valida que el mapa esté rodeado de paredes
	{
		ft_printf("Error: Map is not surronded by walls.\n");
		return (0);
	}
	return (1); // Devuelve 1 si el mapa cargó y validó correctamente
}

