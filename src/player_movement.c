/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:34:51 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 18:04:58 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Valida el movimiento
int	can_move_to(t_game *game, int x, int y)
{
	char	tile;

	// Verificamos los límites del mapa
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	// Verificar que no sea una pared
	tile = game->map.grid[y][x];
	if (tile == '1')
		return (0);
	if (tile == '0' || tile == 'C' || tile == 'E')
		return (1);
	return (1);
}

// Recoge coleccionables
void	collect_item(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.collectibles--;
		game->map.grid[y][x] = '0';
	}
}

// Verifica la victoria
int	check_win_condition(t_game *game)
{
	char	current_tile;

	current_tile = game->map.grid[game->player.y][game->player.x];
	if (current_tile == 'E' && game->map.collectibles == 0)
	{
		ft_printf("You won! Moves: %d\n", game->player.moves);
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

// Función para actualiar solo las posiciones cambiadas
void	update_player_position(t_game *game, int old_x, int old_y, int new_x,
		int new_y)
{
	// 1. Colocar suelo en la posición anterior
	mlx_image_to_window(game->mlx, game->floor.ptr, old_x * TILE_SIZE, old_y
		* TILE_SIZE);
	// 2. Colocar la base en la nueva posición (suelo o salida)
	mlx_image_to_window(game->mlx, game->floor.ptr, new_x * TILE_SIZE, new_y
		* TILE_SIZE);
}

// Función principal para mover al jugador (dx horizontal, dy vertical)
void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	int		old_x;
	int		old_y;
	char	original_tile;

	if (!game || !game->map.grid)
		return ;
	old_x = game->player.x;
	old_y = game->player.y;
	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (can_move_to(game, new_x, new_y))
	{
		original_tile = game->map.grid[new_y][new_x];
		update_player_coordinates(game, new_x, new_y);
		update_player_position(game, old_x, old_y, new_x, new_y);
		collect_item(game, new_x, new_y);
		update_map_grid(game, old_x, old_y, new_x, new_y, original_tile);
		render_exit(game);
		mlx_image_to_window(game->mlx, game->player_img.ptr, new_x * TILE_SIZE,
			new_y * TILE_SIZE);
		check_win_condition(game);
	}
}
