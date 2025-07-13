/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:26:59 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/12 18:42:39 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Validar que haya exactamente un jugador
int	validate_player_count(t_map *map)
{
	if (map->player != 1)
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
	if (map->exit != 1)
	{
		ft_printf("Error: Map must contain exactly one exit.\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!validate_player_count(map))
		return (0);
	if (!validate_collectibles(map))
		return (0);
	if (!validate_exit_count(map))
		return (0);
	if (!validate_map_walls(map))
		return (0);
	return (1);
}
