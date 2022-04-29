/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:46:11 by younglee          #+#    #+#             */
/*   Updated: 2022/04/29 22:23:35 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->fd = -1;
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
