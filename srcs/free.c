/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:51:42 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 15:53:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "so_long.h"

static void	free_mlx_image(void *mlx, void **image)
{
	mlx_destroy_image(mlx, *image);
	*image = NULL;
}

static void	free_enemy_resources(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < SPRITE_NUM)
	{
		if (game->enemy_image[idx] != NULL)
			free_mlx_image(game->mlx, &game->enemy_image[idx]);
		idx++;
	}
}

static void	free_character_resources(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < SPRITE_NUM)
	{
		if (game->character_image[idx] != NULL)
			free_mlx_image(game->mlx, &game->character_image[idx]);
		idx++;
	}
}

static void	free_mlx_resources(t_game *game)
{
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->space_image != NULL)
		free_mlx_image(game->mlx, &game->space_image);
	if (game->wall_image != NULL)
		free_mlx_image(game->mlx, &game->wall_image);
	if (game->exit_close_image != NULL)
		free_mlx_image(game->mlx, &game->exit_close_image);
	if (game->exit_open_image != NULL)
		free_mlx_image(game->mlx, &game->exit_open_image);
	if (game->collectible_image != NULL)
		free_mlx_image(game->mlx, &game->collectible_image);
	free_enemy_resources(game);
	free_character_resources(game);
}

void	free_all_resources(t_game *game)
{
	int	idx;

	if (game->fd != -1)
	{
		close(game->fd);
		game->fd = -1;
	}
	if (game->map != NULL)
	{
		idx = 0;
		while (game->map[idx] != NULL)
		{
			free(game->map[idx]);
			game->map[idx] = NULL;
			idx++;
		}
		free(game->map);
		game->map = NULL;
	}
	free_mlx_resources(game);
}
