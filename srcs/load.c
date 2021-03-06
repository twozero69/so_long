/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:30:51 by younglee          #+#    #+#             */
/*   Updated: 2022/05/09 18:41:06 by younglee         ###   ########seoul.kr  */
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
		exit_with_mlx_error(2, game);
}

void	load_images(t_game *game)
{
	load_xpm_image(&game->space_image, "images/space.xpm", game);
	load_xpm_image(&game->wall_image, "images/wall.xpm", game);
	load_xpm_image(&game->exit_close_image, "images/exit_close.xpm", game);
	load_xpm_image(&game->exit_open_image, "images/exit_open.xpm", game);
	load_xpm_image(&game->collectible_image, "images/collectible.xpm", game);
	load_xpm_image(&game->character_image, "images/character1.xpm", game);
}
