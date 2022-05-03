/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:16:22 by younglee          #+#    #+#             */
/*   Updated: 2022/05/03 15:13:56 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "so_long.h"

int	check_collision_enemy(int row, int col, t_list *enemy)
{
	t_position	*pos;

	while (enemy != NULL)
	{
		pos = enemy->content;
		if (pos->row == row && pos->col == col)
			return (TRUE);
		enemy = enemy->next;
	}
	return (FALSE);
}

static void	set_random_position(t_position *pos, t_game *game)
{
	int		row;
	int		col;

	while (TRUE)
	{
		srand(clock());
		row = rand() % game->height;
		srand(clock());
		col = rand() % game->width;
		if (game->map[row][col] != '0')
			continue ;
		if (game->position.row == row && game->position.col == col)
			continue ;
		if (check_collision_enemy(row, col, game->enemy))
			continue ;
		break ;
	}
	pos->row = row;
	pos->col = col;
}

void	create_enemy(t_game *game)
{
	int			enemy_num;
	int			idx;
	t_position	*pos;
	t_list		*new_list;

	errno = 0;
	enemy_num = game->width * game->height / 50;
	idx = 0;
	while (idx < enemy_num)
	{
		pos = (t_position *)malloc(sizeof(t_position));
		exit_with_clib_error(game);
		new_list = ft_lstnew(pos);
		exit_with_clib_error(game);
		set_random_position(pos, game);
		ft_lstadd_back(&game->enemy, new_list);
		idx++;
	}
}

void	check_enemy(t_game *game)
{
	if (!check_collision_enemy(game->position.row, game->position.col, \
	game->enemy))
		return ;
	printf("You are defeated by the enemy.\n");
	free_all_resources(game);
	exit(0);
}

void	render_enemy(t_game *game)
{
	t_list		*enemy;
	t_position	*pos;

	enemy = game->enemy;
	while (enemy != NULL)
	{
		pos = enemy->content;
		render_image(pos->row, pos->col, game->enemy_image[game->sprite_count], \
		game);
		enemy = enemy->next;
	}
}
