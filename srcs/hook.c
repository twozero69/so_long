/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:27:45 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 23:31:55 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "so_long.h"

static void	check_exit(t_game *game)
{
	int	row;
	int	col;

	row = game->position.row;
	col = game->position.col;
	if (game->map[row][col] != 'E' || game->collectible != 0)
		return ;
	printf("Congratulations. You clear game with %d moves.\n", game->move_count);
	mlx_loop_end(game->mlx);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_character(-1, 0, game);
	else if (keycode == A_KEY)
		move_character(0, -1, game);
	else if (keycode == S_KEY)
		move_character(1, 0, game);
	else if (keycode == D_KEY)
		move_character(0, 1, game);
	else if (keycode == ESC_KEY)
	{
		printf("You ESC key press. Give up the game.\n");
		mlx_loop_end(game->mlx);
	}
	return (0);
}

int	exit_hook(t_game *game)
{
	printf("You press Exit button. Give up the game\n");
	mlx_loop_end(game->mlx);
	return (0);
}

static void	check_collectible(t_game *game)
{
	int	row;
	int	col;

	row = game->position.row;
	col = game->position.col;
	if (game->map[row][col] != 'C')
		return ;
	game->map[row][col] = '0';
	game->collectible--;
}

int	loop_hook(t_game *game)
{
	clock_t	end_time;
	double	current_fps;

	end_time = clock();
	current_fps = CLOCKS_PER_SEC / (double)(end_time - game->start_time);
	if (current_fps >= FPS)
		return (0);
	game->start_time = end_time;
	// if (game->sprite_count == 0)
	// 	move_enemy(game);
	check_collectible(game);
	// check enemy(game);
	check_exit(game);
	game->move_flag = TRUE;
	render(game);
	game->sprite_count = (game->sprite_count + 1) % SPRITE_NUM;
	return (0);
}
