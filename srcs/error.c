/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:54 by younglee          #+#    #+#             */
/*   Updated: 2022/04/27 16:19:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

void	free_all_resources(t_game *game)
{
	int	idx;

	if (game->fd != -1)
		close(game->fd);
	if (game->map != NULL)
	{
		idx = 0;
		while (game->map[idx] != NULL)
		{
			free(game->map[idx]);
			idx++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	exit_with_custom_error(int my_errno, t_game *game)
{
	perror("Error\n");
	perror("custom error %d: ", my_errno);
	if (my_errno == 1)
		perror("A map must be given as an argument.\n");
	else if (my_errno == 2)
		perror("Only one map must be given as an argument.\n");
	else if (my_errno == 3)
		perror("The map is not rectangular.\n");
	else if (my_errno == 4)
		perror("The map has invalid character.\n");
	else if (my_errno == 5)
		perror("The map is not surrounded by walls.\n");
	else if (my_errno == 6)
		perror("There must be only one starting point on the map.\n");
	else if (my_errno == 7)
		perror("There must be at least one collectible on the map.\n");
	else if (my_errno == 8)
		perror("There must be at least one exit on the map.\n");
	else
		perror("Invalid error no.\n");
	free_all_resources(game);
	exit(my_errno);
}

void	exit_with_clib_error(t_game *game)
{
	if (errno == 0)
		return ;
	perror("Error\n");
	perror("clib error %d: %s\n", errno, strerror(errno));
	free_all_resources(game);
	exit(errno);
}
