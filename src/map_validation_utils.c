/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:16:32 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:23:44 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verifica si todos los caracteres de una cadena son iguales a 'c'
static int	ft_strall(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

// Validar que haya muros
int	validate_map_walls(t_map *map)
{
	int	i;

	// Validar que la primera y última fila estén rodeadas de muros ('1')
	if (!ft_strall(map->grid[0], '1') || !ft_strall(map->grid[map->height - 1],
			'1'))
	{
		ft_printf("Error: Map is not surrounded by walls.\n");
		return (0);
	}
	// Validar que las columnas de los bordes estén rodeadas de muros ('1')
	i = 1;
	while (i < map->height - 1)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			ft_printf("Error: Map is not surrounded by walls.\n");
			return (0);
		}
		i++;
	}
	return (1); // Éxito
}

// Valida que el mapa sea rectangular
int	validate_map_rectangle(t_map *map)
{
	int	i;
	int	first_row_len;

	if (!map->grid || !map->grid[0])
		return (0);
	first_row_len = (int)ft_strlen(map->grid[0]);
	map->width = first_row_len; // Establece el ancho del mapa
	i = 1;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != first_row_len)
		{
			ft_printf("Error: Map is not rectangular.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// Valida caracteres válidos en el mapa
int	validate_map_chars(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] != '0' && map->grid[i][j] != '1' &&
				map->grid[i][j] != 'P' && map->grid[i][j] != 'E' &&
				map->grid[i][j] != 'C')
			{
				ft_printf("Error: Invalid character '%c' in map.\n", map->grid[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Valida que la extencion del archivo sea .ber
int	validate_file_extension(char *filename)
{
	char	*extension;
	int		len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	extension = filename + len - 4;
	if (ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_printf("Error: File must have .ber extension.\n");
		return (0);
	}
	return (1);
}
