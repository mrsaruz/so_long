/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:20:04 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 13:21:22 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Renderizar un tile específico
static void	render_tile(t_game *game, int x, int y, char tile_type)
{
	if (!game || !game->mlx || !game->floor.ptr)
		return ;
	if (mlx_image_to_window(game->mlx, game->floor.ptr, x * TILE_SIZE, y
		* TILE_SIZE) < 0)
		return ;
	if (tile_type == '1' && game->wall.ptr)
		mlx_image_to_window(game->mlx, game->wall.ptr, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile_type == 'P' && game->player_img.ptr)
		mlx_image_to_window(game->mlx, game->player_img.ptr, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile_type == 'C' && game->collectible.ptr)
		mlx_image_to_window(game->mlx, game->collectible.ptr, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile_type == 'E' && game->exit.ptr)
		mlx_image_to_window(game->mlx, game->exit.ptr, x * TILE_SIZE, y
			* TILE_SIZE);
}

// Renderizar mapa completo
void	render_map(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->map.grid)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
}
