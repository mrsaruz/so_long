/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:26:59 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 19:36:48 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_map(t_map *map)
{
	if (!map || !map->grid)
	{
		ft_printf("Error: Map data is missing.\n");
		return (0);
	}
	if (map->player != 1)
	{
		ft_printf("Error: Map must contain exactly one player.\n");
		return (0);
	}
	if (map->collectibles < 1)
	{
		ft_printf("Error: Map must contain at least one collectible.\n");
		return (0);
	}
	if (map->exit != 1)
	{
		ft_printf("Error: Map must contain exactly one exit.\n");
		return (0);
	}
	if (!validate_map_walls(map))
		return (0);
	return (1);
}
