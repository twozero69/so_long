/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:11:55 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 23:20:26 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	render_image(int row, int col, void *image, t_game *game)
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

void	render(t_game *game)
{
	render_map(game);
	// render_enemy(game);
	render_character(game);
}
