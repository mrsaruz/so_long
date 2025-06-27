/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:46:05 by adruz-to          #+#    #+#             */
/*   Updated: 2025/06/27 17:31:15 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../get_next_line/get_next_line.h>
# include <MLX42.h>
# include <libft.h>
# include <libftprintf.h>
# include <fcntl.h> // Para abrir archivos
# include <unistd.h>
# include <stdlib.h> // malloc y free

// Structure to store an img loaded with MLX
typedef struct s_img
{
	void *ptr;  // puntero a la imagen
	int width;  // ancho en px
	int height; // alto en px
}				t_img;

// Structure representing the player
typedef struct s_player
{
	int x;     // posición x actual del jugador, corresponde a la columna
	int y;     // posición y actual del jugador, corresponde a la fila
	int moves; // contador de movimientos realizados
}				t_player;

// Structure representing the map
typedef struct s_map
{
	char **grid;      // matriz de catacteres que representa el mapa
	int width;        // ancho del mapa (nº columnas)
	int height;       // alto del mapa (nº filas)
	int collectibles; // total de objetos que hay que recoger
	int exits;        // numero de salidas E que debe ser 1
	int players;      // numero de jugadores P que debe ser 1
}				t_map;

// main game structure
typedef struct s_game
{
	void *mlx; // puntero a mlx (mlx init)
	void *win; // puntero a la ventana del juego (mlx new_window)
	t_map map; // mapa del juego
	t_player	player;
	t_img		wall;
	t_img		floor;
	t_img		player_img;
	t_img		collectible;
	t_img		exit;
	int game_state;  // estado del juego(0 en curso, 1 terminado)
	int total_moves; // contador global de movimientos
}				t_game;

//
int				load_map(char *filename, t_map *map);

// main
int				main(int ac, char **av);

#endif