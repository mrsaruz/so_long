/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:57:58 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/21 18:20:33 by adruz-to         ###   ########.fr       */
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
void	update_map_grid(t_game *game, t_coords *old_pos, t_coords *new_pos,
		char original_tile)
{
	if (game->map.grid[old_pos->y][old_pos->x] != 'E')
		game->map.grid[old_pos->y][old_pos->x] = '0';
	if (original_tile != 'E')
		game->map.grid[new_pos->y][new_pos->x] = 'P';
}
