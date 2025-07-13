/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:34:51 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 12:50:45 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Valida el movimiento
int	can_move_to(t_game *game, int x, int y)
{
	// Verificamos los límites del mapa
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	return (1);
}

// Recoge coleccionables
void	collect_item(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.collectibles--;
		ft_printf("Collectibles remaining: %d\n", game->map.collectibles);
	}
}

// Verifica la victoria
int	check_win_condition(t_game *game)
{
	if (game->map.grid[game->player.y][game->player.x] == 'E' && 
		game->map.collectibles == 0)
	{
		ft_printf("You won! Moves: %d\n", game->player.moves);
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

// Función principal para mover al jugador (dx horizontal, dy vertical)
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;

	if (can_move_to(game, new_x, new_y))
	{
		// Actualizar la posición del jugador en el grid
		game->map.grid[game->player.y][game->player.x] = '0';
		game->map.grid[new_y][new_x] = 'P';
		// Actualizar coordenadas del jugador
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.moves++;

		ft_printf("Moves: %d\n", game->player.moves);
		render_map(game);
	}
}
