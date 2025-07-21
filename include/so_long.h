/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:46:05 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/21 18:20:08 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 128          // Tamaño de cada celda del mapa
# define WINDOW_TITLE "so_long" // Título de la ventana

# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>  // Para abrir archivos
# include <stdlib.h> // malloc y free
# include <unistd.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

// Structure for coordinates and dimensions
typedef struct s_coords
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_coords;

// Structure to store an img loaded with MLX
typedef struct s_img
{
	mlx_image_t *ptr; // puntero a la imagen
	int width;        // ancho en px
	int height;       // alto en px
}				t_img;

// Structure representing the player
typedef struct s_player
{
	int x;     // posición X actual del jugador, corresponde a la columna
	int y;     // posición Y actual del jugador, corresponde a la fila
	int moves; // contador de movimientos realizados
}				t_player;

// Structure representing the map
typedef struct s_map
{
	char **grid;      // matriz de catacteres que representa el mapa
	int width;        // ancho del mapa (nº columnas)
	int height;       // alto del mapa (nº filas)
	int collectibles; // total de objetos que hay que recoger
	int exit;         // numero de salidas E que debe ser 1
	int player;       // numero de jugadores P que debe ser 1
	int player_x;     // posición X del jugador
	int player_y;     // posición Y del jugador
}				t_map;

// main game structure
typedef struct s_game
{
	mlx_t *mlx;       // puntero a mlx (mlx init)
	mlx_image_t *win; // puntero a la ventana del juego (mlx new_window)
	t_map map;        // mapa del juego
	t_player	player;
	t_img		wall;
	t_img		floor;
	t_img		player_img;
	t_img		collectible;
	t_img		exit;
	int game_state;  // estado del juego(0 en curso, 1 terminado)
	int total_moves; // contador global de movimientos
}				t_game;

// map validation
int				validate_map(t_map *map);

// map validation utils
int				validate_map_walls(t_map *map);
int				validate_map_rectangle(t_map *map);
int				validate_map_chars(t_map *map);
int				validate_file_extension(char *filename);

// map loader
int				count_map_lines(char *filename);
char			**allocate_map_grid(int height);
int				read_and_trim_line(int fd, char **grid, int i);
int				fill_map_grid(char *filename, char **grid, int height);
void			free_map_grid(char **grid, int count);
void			count_map_elements(t_map *map);
int				load_map(char *filename, t_map *map);

// map utils
void			find_player_position(t_map *map);
void			free_map_grid(char **grid, int height);

// game events
void			key_handler(mlx_key_data_t keydata, void *param);

// run and render game
void			run_game(t_game *game);
void			render_map(t_game *game);
void			render_exit(t_game *game);

// player movements and utils
int				can_move_to(t_game *game, int x, int y);
void			collect_item(t_game *game, int x, int y);
int				check_win_condition(t_game *game);
void			move_player(t_game *game, int dx, int dy);
void			update_player_coordinates(t_game *game, int new_x, int new_y);
void			update_player_position(t_game *game, t_coords *old_pos, 
					t_coords *new_pos);
void			update_map_grid(t_game *game, t_coords *old_pos, 
					t_coords *new_pos, char original_tile);
// main so_long
int				main(int ac, char **av);

// utils
void			close_game(t_game *game);

#endif