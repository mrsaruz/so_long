/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:57:58 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 15:51:35 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Actualiza las coordenadas del jugador
void	update_player_coordinates(t_game *game, int new_x, int new_y)
{
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
}

// Actualiza el grid del mapa
void	update_map_grid(t_game *game, int old_x, int old_y, int new_x,
		int new_y, char original_tile)
{
	game->map.grid[old_y][old_x] = '0';
	if (original_tile != 'E')
		game->map.grid[new_y][new_x] = 'P';
}
