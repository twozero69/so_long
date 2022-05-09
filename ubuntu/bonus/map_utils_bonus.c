/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:35:27 by younglee          #+#    #+#             */
/*   Updated: 2022/05/09 16:27:01 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argc(int argc, t_game *game)
{
	if (argc < 2)
		exit_with_custom_error(1, game);
	if (argc > 2)
		exit_with_custom_error(2, game);
}

void	check_char(char c, t_game *game)
{
	char	*char_str;

	char_str = "01CEP";
	while (*char_str != '\0')
	{
		if (c == *char_str)
			return ;
		char_str++;
	}
	exit_with_custom_error(4, game);
}

void	check_wall(int row, int col, char c, t_game *game)
{
	if (row != 0 && row != game->height - 1 \
	&& col != 0 && col != game->width - 1)
		return ;
	if (c == '1')
		return ;
	exit_with_custom_error(5, game);
}

void	check_start(int row, int col, t_game *game)
{
	if (game->position.row == 0 && game->position.col == 0)
	{
		game->position.row = row;
		game->position.col = col;
		game->map[row][col] = '0';
		return ;
	}
	exit_with_custom_error(6, game);
}

void	check_token(t_game *game)
{
	if (game->position.row == 0 && game->position.col == 0)
		exit_with_custom_error(6, game);
	if (game->collectible == 0)
		exit_with_custom_error(7, game);
	if (game->exit == 0)
		exit_with_custom_error(8, game);
}
