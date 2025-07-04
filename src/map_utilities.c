/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:04:06 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/04 13:33:38 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Calcala la altura del mapa leyendo el archivo línea por línea
int	count_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY); // Abrir archivo en modo lectura
	if (fd < 0)
	{
		ft_printf("Error: Could not open the file.\n");
		return (-1); // Devuelve -1 en caso de error
	}
	while ((line = get_next_line(fd))) // Lee línea por línea y cuenta
	{
		free(line); // Liberamos memoria de la línea leída
		height++;   // Incrementamos la altura por cada línea
	}
	clode(fd);       // Cerramos el archivo
	return (height); // Devuelve la altura calculada
}

// Asigna memoria para la matriz map->grid
char	**allocate_map_grid(int height)
{
	char	**grid;

	grid = malloc(sizeof(char *) * height);
	if (!grid)
	{
		ft_printf("Error: Memory allocation failed for map grid\n");
		return (NULL);
	}
	return (grid);
}

// Llena la matriz map->grid con las líneas del archivo
int	fill_map_grid(char filename, char **grid, int height)
{
}

// Cuenta los elementos importantes(C, P, E) en el mapa
void	count_map_elements(t_map *map)
{
}

// Valida que el mapa esté rodeado de paredes
int	validate_map_walls(t_map *map)
{
}
