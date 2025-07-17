/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:45:56 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/17 15:55:47 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_game(t_game *game)
{
	// Inicializammos los punteros a NULL
	game->mlx = NULL;
	// Inicializamos la estructura del mapa
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	// Inicializamos la estructura del jugador
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	// Inicializar imágenes a NULL (inicializa los punteros de las texturas a NULL)
	game->wall.ptr = NULL;
	game->floor.ptr = NULL;
	game->player_img.ptr = NULL;
	game->collectible.ptr = NULL;
	game->exit.ptr = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2) // verificamos el argumento
	{
		ft_printf("Error: You must provide a .ber file as an argument\n");
		return (EXIT_FAILURE); // retorno extandar de salida
	}
	init_game(&game); // inicializa la estructura del juego
	if (!load_map(av[1], &game.map) || !validate_map(&game.map))
	// cargamos el mapay validamos que sea correcto
	{
		ft_printf("Error: Failed to load or validate the map.\n");
		close_game(&game); // Liberar recursos so algo falla
		return (EXIT_FAILURE);
	}
	game.player.x = game.map.player_x;
	game.player.y = game.map.player_y;
	run_game(&game);   // Ejecutar el bucle del juego
	close_game(&game); // Liberar recursos al salir, asegura la limpieza
	return (EXIT_SUCCESS);
}
