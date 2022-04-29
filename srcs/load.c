/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:30:51 by younglee          #+#    #+#             */
/*   Updated: 2022/04/29 22:23:15 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	load_xpm_image(void **image, char *file, t_game *game)
{
	int	img_width;
	int	img_height;

	*image = mlx_xpm_file_to_image(game->mlx, file, &img_width, &img_height);
	if (*image == NULL || img_width != IMG_SIZE || img_height != IMG_SIZE)
		exit_with_mlx_error(1, game);
}

void	load_images(t_game *game)
{
	load_xpm_image(&game->space_image, "images/space.xpm", game);
	load_xpm_image(&game->wall_image, "images/wall.xpm", game);
	load_xpm_image(&game->exit_close_image, "images/exit_close.xpm", game);
	load_xpm_image(&game->exit_open_image, "images/exit_open.xpm", game);
	load_xpm_image(&game->collectible_image, "images/collectible.xpm", game);
	load_xpm_image(&game->enemy_image[0], "images/enemy1.xpm", game);
	load_xpm_image(&game->enemy_image[1], "images/enemy2.xpm", game);
	load_xpm_image(&game->enemy_image[2], "images/enemy3.xpm", game);
	load_xpm_image(&game->enemy_image[3], "images/enemy4.xpm", game);
	load_xpm_image(&game->character_image[0], "images/character1.xpm", game);
	load_xpm_image(&game->character_image[1], "images/character2.xpm", game);
	load_xpm_image(&game->character_image[2], "images/character3.xpm", game);
	load_xpm_image(&game->character_image[3], "images/character4.xpm", game);
}
