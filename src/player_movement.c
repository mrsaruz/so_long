/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:34:51 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/21 18:26:13 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Valida el movimiento
int	can_move_to(t_game *game, int x, int y)
{
	char	tile;

	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
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
void	update_player_position(t_game *game, t_coords *old_pos,
		t_coords *new_pos)
{
	mlx_image_to_window(game->mlx, game->floor.ptr, old_pos->x * TILE_SIZE,
		old_pos->y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->floor.ptr, new_pos->x * TILE_SIZE,
		new_pos->y * TILE_SIZE);
}

// Función principal para mover al jugador (dx horizontal, dy vertical)
void	move_player(t_game *game, int dx, int dy)
{
	t_coords	old_pos;
	t_coords	new_pos;
	char		original_tile;

	if (!game || !game->map.grid)
		return ;
	old_pos.x = game->player.x;
	old_pos.y = game->player.y;
	new_pos.x = game->player.x + dx;
	new_pos.y = game->player.y + dy;
	if (can_move_to(game, new_pos.x, new_pos.y))
	{
		original_tile = game->map.grid[new_pos.y][new_pos.x];
		update_player_coordinates(game, new_pos.x, new_pos.y);
		update_player_position(game, &old_pos, &new_pos);
		collect_item(game, new_pos.x, new_pos.y);
		update_map_grid(game, &old_pos, &new_pos, original_tile);
		render_exit(game);
		mlx_image_to_window(game->mlx, game->player_img.ptr, new_pos.x
			* TILE_SIZE, new_pos.y * TILE_SIZE);
		check_win_condition(game);
	}
}
