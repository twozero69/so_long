/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:36:41 by younglee          #+#    #+#             */
/*   Updated: 2022/04/29 22:24:03 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	play_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(\
		game->mlx, \
		game->width * IMG_SIZE, \
		game->height * IMG_SIZE, \
		"so_long"\
	);
	if (game->window == NULL)
		exit_with_mlx_error(2, game);
	load_images(game);
	mlx_loop(game->mlx);
}
