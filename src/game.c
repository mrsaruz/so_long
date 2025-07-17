/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:30:42 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 13:24:56 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Función auxiliar para cargar una textura individual
static mlx_image_t	*load_img(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(game->mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}

// Carga texturas básicas (jugador, pared y suelo)
static int	load_basic_textures(t_game *game)
{
	game->player_img.ptr = load_img(game, "textures/player.png");
	if (!game->player_img.ptr)
		return (0);
	game->wall.ptr = load_img(game, "textures/wall.png");
	if (!game->wall.ptr)
		return (0);
	game->floor.ptr = load_img(game, "textures/floor.png");
	if (!game->floor.ptr)
		return (0);
	return (1);
}

// Carga texturas de elementos del juego
static int	load_game_textures(t_game *game)
{
	game->collectible.ptr = load_img(game, "textures/collectible.png");
	if (!game->collectible.ptr)
		return (0);
	game->exit.ptr = load_img(game, "textures/exit.png");
	if (!game->exit.ptr)
		return (0);
	return (1);
}

// Inicializar MLX
static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height
			* TILE_SIZE, WINDOW_TITLE, true);
	if (!game->mlx)
		return (0);
	return (1);
}

// Función principal del juego
void	run_game(t_game *game)
{
	if (!init_mlx(game))
		return ;
	if (!load_basic_textures(game) || !load_game_textures(game))
		return ;
	render_map(game);
	mlx_key_hook(game->mlx, key_handler, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
