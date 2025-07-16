/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:30:42 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/16 18:36:30 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Función auxiliar para cargar una textura individual
static mlx_image_t	*load_img(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	ft_printf("Trying to load: %s\n", path);
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("Failed to load XPM: %s\n", path);
		return (NULL);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	if (!image)
	{
		ft_printf("Failed to convert texture to image: %s\n", path);
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	ft_printf("Successfully loaded: %s\n", path);
	return (image);
}

// Carga texturas básicas (jugador, pared y suelo)
static int	load_basic_textures(t_game *game)
{
	game->player_img.ptr = load_img(game, "textures/player.png");
	if (!game->player_img.ptr)
	{
		ft_printf("Error: Failed to load player texture.\n");
		return (0);
	}
	game->wall.ptr = load_img(game, "textures/wall.png");
	if (!game->wall.ptr)
	{
		ft_printf("Error: Failed to load wall texture.\n");
		return (0);
	}
	game->floor.ptr = load_img(game, "textures/floor.png");
	if (!game->floor.ptr)
	{
		ft_printf("Error: Failed to load floor texture.\n");
		return (0);
	}
	return (1);
}

// Carga texturas de elementos del juego
static int	load_game_textures(t_game *game)
{
	game->collectible.ptr = load_img(game, "textures/collectible.png");
	if (!game->collectible.ptr)
	{
		ft_printf("Error: Failed to load collectible texture.\n");
		return (0);
	}
	game->exit.ptr = load_img(game, "textures/exit.png");
	if (!game->exit.ptr)
	{
		ft_printf("Error: Failed to load exit texture.\n");
		return (0);
	}
	return (1);
}

// Inicializar MLX
static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height
			* TILE_SIZE, WINDOW_TITLE, true);
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX.\n");
		return (0);
	}
	return (1);
}

// Función principal del juego
void	run_game(t_game *game)
{
	ft_printf("Starting game initialization...\n");
	if (!init_mlx(game))
	{
		ft_printf("MLX initialization failed!\n");
		return ;
	}
	ft_printf("MLX initialization successfully\n");
	if (!load_basic_textures(game) || !load_game_textures(game))
	{
		ft_printf("Textures loading failed!\n");
		return ;
	}
	ft_printf("All textures loaded successfully\n");
	render_map(game);
	ft_printf("Map rendered, setting up events...\n");
	ft_printf("DEBUG: About to set key hook...\n");
	mlx_key_hook(game->mlx, key_handler, game);
	ft_printf("DEBUG: Key hook set successfully\n");
	ft_printf("DEBUG: About to start main loop...\n");
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_printf("DEBUG: Main loop ended\n");
}
