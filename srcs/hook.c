/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:27:45 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 17:06:35 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "so_long.h"

static void	move(int dy, int dx, t_game *game)
{
	int	next_row;
	int	next_col;

	if (!game->move_flag)
		return ;
	game->move_flag = FALSE;
	game->move_count++;
	next_row = game->position.row + dy;
	next_col = game->position.col + dx;
	if (game->map[next_row][next_col] != '1')
	{
		game->position.row = next_row;
		game->position.col = next_col;
	}
	printf("Move count: %d\n", game->move_count);
	printf("%d %d\n", game->position.row, game->position.col);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move(-1, 0, game);
	else if (keycode == A_KEY)
		move(0, -1, game);
	else if (keycode == S_KEY)
		move(1, 0, game);
	else if (keycode == D_KEY)
		move(0, 1, game);
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

int	loop_hook(t_game *game)
{
	game->move_flag = TRUE;
	return (0);
}
