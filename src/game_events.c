/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:50:04 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/16 18:37:39 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Manejar eventos de teclado
void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	ft_printf("DEBUG: Key handler called with key: %d\n", keydata.key);

	if (!param)
	{
		ft_printf("DEBUG: param is NULL\n");
		return ;
	}
	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_W)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, 1, 0);
	}
}
