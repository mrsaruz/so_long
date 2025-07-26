/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:31:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/26 19:26:17 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Calcala la altura del mapa leyendo el archivo línea por línea.
int	count_map_lines(char *filename)
{
	int		fd;
	char	*line;
	int		lines;
	int		len;

	fd = open(filename, O_RDONLY); // Abrir archivo en modo lectura
	if (fd < 0)
		return (0);
	lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'
				|| line[len - 1] == '\n'))
			len--;
		if (len > 0) // Solo cuenta las líneas no vacías
			lines++;
		free(line);
	}
	close(fd);
	// Limpiar la variable estática de get_next_line
	// gnl_cleanup();
	return (lines);
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
	grid[height] = NULL;
	// Terminamos con NULL para indicar dónde acaba el array
	return (grid);
}

// Llena el grid
int	read_and_trim_line(int fd, char **grid, int i)
{
	char	*line;
	char	*trimmed;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		trimmed = ft_strtrim(line, " \t\n\r");
		free(line);
		if (!trimmed)
			return (0);
		if (*trimmed)
		{
			grid[i] = trimmed;
			return (1);
		}
		free(trimmed);
	}
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
	int	i;
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < height)
	{
		if (!read_and_trim_line(fd, grid, i))
		{
			free_grid_error(grid, i);
			close(fd);
			// Limpiar la variable estática de get_next_line en caso de error
			// gnl_cleanup();
			return (0);
		}
		i++;
	}
	close(fd);
	// Limpiar la variable estática de get_next_line
	// gnl_cleanup();
	return (1);
}
