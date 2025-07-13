/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:30:42 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 17:24:26 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Función auxiliar para cargar una textura individual
static mlx_image_t	*load_img(t_game *game, char *path)
{
	xpm_t			*xpm;
	mlx_image_t		*image;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		return (NULL);
	image = mlx_texture_to_image(game->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (image);
}

// Carga texturas básicas (jugador, pared y suelo)
static int	load_basic_textures(t_game *game)
{
	game->player_img.ptr = load_img(game, "../textures/player.xpm");
	if (!game->player_img.ptr)
	{
		ft_printf("Error: Failed to load player texture.\n");
		return (0);
	}
	game->wall.ptr = load_img(game, "../textures/wall.xpm");
	if (!game->wall.ptr)
	{
		ft_printf("Error: Failed to load wall texture.\n");
		return (0);
	}
	game->floor.ptr = load_img(game, "../textures/background.xpm");
	if (!game->floor.ptr)
	{
		ft_printf("Error: Failed to load background texture.\n");
		return (0);
	}
	return (1);
}

// Carga texturas de elementos del juego
static int	load_game_textures(t_game *game)
{
	game->collectible.ptr = load_img(game, "../textures/collectible.xpm");
	if (!game->collectible.ptr)
	{
		ft_printf("Error: Failed to load collectible texture.\n");
		return (0);
	}
	game->exit.ptr = load_img(game, "../textures/exit.xpm");
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
	game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, WINDOW_TITLE, true);
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
	if (!init_mlx(game))
		return ;
	if (!load_basic_textures(game) || !load_game_textures(game))
	{
		mlx_terminate(game->mlx);
		return ;
	}
	render_map(game);
	mlx_key_hook(game->mlx, key_handler, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
