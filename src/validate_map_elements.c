/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:26:59 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/04 15:34:27 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Validar que haya exactamente un jugador
int	validate_player_count(t_map *map)
{
	if (map->players != 1)
	{
		ft_printf("Error: Map must contain exactly one player.\n");
		return (0);
	}
	return (1);
}

// Validar que haya al menos un coleccionable
int	validate_collectibles(t_map *map)
{
	if (map->collectibles < 1)
	{
		ft_printf("Error: Map must contain at least one collectible.\n");
		return (0);
	}
	return (1);
}

// Validar que haya una salida
int	validate_exit_count(t_map *map)
{
	if (map->exits != 1)
	{
		ft_printf("Error: Map must contain exactly one exit.\n");
		return (0);
	}
	return (1);
}

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
