/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:46:11 by younglee          #+#    #+#             */
/*   Updated: 2022/04/28 11:58:46 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	init_game(t_game *game)
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
}
