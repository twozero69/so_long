/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:20:01 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 23:31:36 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "so_long.h"

void	move_character(int dy, int dx, t_game *game)
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
}
