/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:11:55 by younglee          #+#    #+#             */
/*   Updated: 2022/05/09 17:12:13 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "so_long_bonus.h"

void	render_image(int row, int col, void *image, t_game *game)
{
	if (mlx_put_image_to_window(game->mlx, game->window, image, \
	col * IMG_SIZE, row * IMG_SIZE) == FALSE)
		exit_with_mlx_error(4, game);
}

static void	render_map(t_game *game)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			c = game->map[row][col];
			if (c == '0')
				render_image(row, col, game->space_image, game);
			else if (c == '1')
				render_image(row, col, game->wall_image, game);
			else if (c == 'C')
				render_image(row, col, game->collectible_image, game);
			else if (c == 'E' && game->collectible > 0)
				render_image(row, col, game->exit_close_image, game);
			else if (c == 'E' && game->collectible == 0)
				render_image(row, col, game->exit_open_image, game);
			col++;
		}
		row++;
	}
}

static void	render_character(t_game *game)
{
	render_image(game->position.row, game->position.col, \
	game->character_image[game->sprite_count], game);
}

static void	render_move_count(t_game *game)
{
	char	*move_count_str;
	int		move_count_row;
	int		move_count_col;
	int		color;

	errno = 0;
	move_count_str = ft_itoa(game->move_count);
	exit_with_clib_error(game);
	move_count_col = (game->position.col + 0.85) * IMG_SIZE;
	move_count_row = (game->position.row + 0.95) * IMG_SIZE;
	color = 0x00FFFFFF;
	if (mlx_string_put(game->mlx, game->window, move_count_col, \
	move_count_row, color, move_count_str) == FALSE)
		exit_with_mlx_error(6, game);
	free(move_count_str);
}

void	render(t_game *game)
{
	render_map(game);
	render_enemy(game);
	render_character(game);
	render_move_count(game);
}
