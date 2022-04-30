/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:46:11 by younglee          #+#    #+#             */
/*   Updated: 2022/05/01 03:46:38 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "so_long.h"

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->fd = -1;
}

static void	play_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_with_mlx_error(1, game);
	game->window = mlx_new_window(game->mlx, game->width * IMG_SIZE, \
	game->height * IMG_SIZE, "so_long");
	if (game->window == NULL)
		exit_with_mlx_error(3, game);
	load_images(game);
	mlx_hook(game->window, KEYPRESS, KEYPRESSMASK, key_hook, game);
	mlx_hook(game->window, DESTROYNOTIFY, STRUCTURENOTIFYMASK, exit_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	create_enemy(game);
	game->mlx_error_ignore = TRUE;
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	check_argc(argc, &game);
	check_map(argv[1], &game);
	play_game(&game);
	free_all_resources(&game);
}
