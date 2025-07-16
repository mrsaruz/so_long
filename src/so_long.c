/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:45:56 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/16 18:29:54 by adruz-to         ###   ########.fr       */
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
	// Inicializamos la estructura del jugador (se establece la posición inicial y el contador de movimientos)
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
	ft_printf("DEBUG: Initializing game...\n");
	init_game(&game); // inicializa la estructura del juego
	ft_printf("DEBUG: Game initialized\n");

	ft_printf("DEBUG: Loading map: %s\n", av[1]);
	if (!load_map(av[1], &game.map) || !validate_map(&game.map)) // cargamos el mapay validamos que sea correcto
	{
		ft_printf("Error: Failed to load or validate the map.\n");
		close_game(&game); // Liberar recursos so algo falla
		ft_printf("DEBUG: close_game completed from error path\n");
		return (EXIT_FAILURE);
	}
	ft_printf("DEBUG: Map loaded successfully, about to run game\n");
	run_game(&game); // Ejecutar el bucle del juego
	ft_printf("DEBUG: Game finished, about to call close_game\n");
	close_game(&game);   // Liberar recursos al salir, asegura la limpieza
	ft_printf("DEBUG: close_game completed normally\n");
	return (EXIT_SUCCESS);
}
