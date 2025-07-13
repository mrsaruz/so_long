/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:55:04 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/12 15:24:35 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(t_game *game)
{
	int i;
	// Liberar la matriz del mapa
	if (game->map.grid)
	{
		i = 0;
		while(i < game->map.height)
			free(game->map.grid[i++]);
		free(game->map.grid);
		game->map.grid = NULL;
	}
	if (game->wall.ptr) // Destruir imágenes de MLX
		mlx_delete_image(game->mlx, game->wall.ptr);
	if (game->floor.ptr)
		mlx_delete_image(game->mlx, game->floor.ptr);
	if (game->player_img.ptr)
		mlx_delete_image(game->mlx, game->player_img.ptr);
	if (game->collectible.ptr)
		mlx_delete_image(game->mlx, game->collectible.ptr);
	if (game->exit.ptr)
		mlx_delete_image(game->mlx, game->exit.ptr);
	// Cerrar la ventan de MLX y liberar
	if (game->win)
		mlx_close_window(game->mlx);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
