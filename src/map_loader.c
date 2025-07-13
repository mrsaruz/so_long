/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 17:28:56 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Calcala la altura del mapa leyendo el archivo línea por línea
int	count_map_lines(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY); // Abrir archivo en modo lectura
	if (fd < 0)
	{
		ft_printf("Error: Could not open the file.\n");
		return (-1); // Devuelve -1 en caso de error
	}
	height = 0;
	line = get_next_line(fd);
	while (line) // Lee línea por línea y cuenta
	{
		free(line); // Liberamos memoria de la línea leída
		height++;   // Incrementamos la altura por cada línea
		line = get_next_line(fd);
	}
	close(fd);       // Cerramos el archivo
	return (height); // Devuelve la altura calculada
}

// Asigna memoria para la matriz map->grid
char	**allocate_map_grid(int height)
{
	char	**grid;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
	{
		ft_printf("Error: Memory allocation failed for map grid\n");
		return (NULL);
	} 
	grid[height] = NULL; // Terminamos con NULL para indicar dónde acaba el array
	return (grid);
}

// read_and_trim_line
int	read_and_trim_line(int fd, char **grid, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);

	grid[i] = ft_strtrim(line, "\n");
	free(line);

	if (!grid[i])
		return (0);

	return (1);
}

// Ayuda para limpiar memoria parcial
void	free_grid_error(char **grid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(grid[i]);
		i++;
	}
}

// Llena la matriz map->grid con los datos del archivo
int	fill_map_grid(char *filename, char **grid, int height)
{
	int i;
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while(i < height)
	{
		if (!read_and_trim_line(fd, grid, i))
		{
			free_grid_error(grid, i);
			close(fd);
			return (0);
		}
		i++;
	}
	close(fd);
	return (1);
}
