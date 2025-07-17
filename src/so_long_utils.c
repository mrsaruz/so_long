/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:55:04 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 15:54:00 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Libera las imágenes de MLX42
/* static void	free_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->wall.ptr)
		mlx_delete_image(game->mlx, game->wall.ptr);
	if (game->floor.ptr)
		mlx_delete_image(game->mlx, game->floor.ptr);
	if (game->player_img.ptr)
		mlx_delete_image(game->mlx, game->player_img.ptr);
	if (game->collectible.ptr)
		mlx_delete_image(game->mlx, game->collectible.ptr);
	if (game->exit.ptr)
		mlx_delete_image(game->mlx, game->exit.ptr);
} */

// Libera la matriz del mapa
static void	free_map(t_game *game)
{
	int	i;

	if (!game || !game->map.grid)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i])
			free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}

// Función principal
void	close_game(t_game *game)
{
	if (!game)
		return ;

	free_map(game);
	if (game->mlx)
		game->mlx = NULL;
}
