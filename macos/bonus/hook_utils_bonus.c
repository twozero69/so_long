/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:20:01 by younglee          #+#    #+#             */
/*   Updated: 2022/05/09 18:33:04 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "so_long_bonus.h"

void	move_character(int dy, int dx, t_game *game)
{
	int	next_row;
	int	next_col;

	if (!game->move_flag)
		return ;
	game->move_flag = FALSE;
	next_row = game->position.row + dy;
	next_col = game->position.col + dx;
	if (game->map[next_row][next_col] != '1')
	{
		game->position.row = next_row;
		game->position.col = next_col;
		game->move_count++;
		printf("Move count: %d\n", game->move_count);
	}
}

static int	check_enable_dir(int row, int col, t_game *game)
{
	if (game->map[row][col] == '1')
		return (FALSE);
	if (check_collision_enemy(row, col, game->enemy))
		return (FALSE);
	return (TRUE);
}

static void	check_enable_dirs(t_position *pos, int *enable_dir, \
int *enable_cnt, t_game *game)
{
	if (check_enable_dir(pos->row - 1, pos->col, game))
	{
		enable_dir[*enable_cnt] = 0;
		(*enable_cnt)++;
	}
	if (check_enable_dir(pos->row, pos->col - 1, game))
	{
		enable_dir[*enable_cnt] = 1;
		(*enable_cnt)++;
	}
	if (check_enable_dir(pos->row + 1, pos->col, game))
	{
		enable_dir[*enable_cnt] = 2;
		(*enable_cnt)++;
	}
	if (check_enable_dir(pos->row, pos->col + 1, game))
	{
		enable_dir[*enable_cnt] = 3;
		(*enable_cnt)++;
	}
}

static void	move_enemy(t_position *pos, t_game *game)
{
	int	enable_dir[4];
	int	enable_cnt;
	int	next_dir;

	enable_cnt = 0;
	check_enable_dirs(pos, enable_dir, &enable_cnt, game);
	if (enable_cnt == 0)
		return ;
	srand(clock());
	next_dir = enable_dir[rand() % enable_cnt];
	if (next_dir == 0)
		pos->row--;
	else if (next_dir == 1)
		pos->col--;
	else if (next_dir == 2)
		pos->row++;
	else if (next_dir == 3)
		pos->col++;
}

void	move_enemy_list(t_game *game)
{
	t_list	*enemy;

	enemy = game->enemy;
	while (enemy != NULL)
	{
		move_enemy(enemy->content, game);
		enemy = enemy->next;
	}
}
