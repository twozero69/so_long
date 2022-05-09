/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:54 by younglee          #+#    #+#             */
/*   Updated: 2022/05/09 16:26:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

void	exit_with_custom_error(int my_errno, t_game *game)
{
	printf("Error\n");
	printf("custom error %d: ", my_errno);
	if (my_errno == 1)
		printf("A map must be given as an argument.\n");
	else if (my_errno == 2)
		printf("Only one map must be given as an argument.\n");
	else if (my_errno == 3)
		printf("The map is not rectangular.\n");
	else if (my_errno == 4)
		printf("The map has invalid character.\n");
	else if (my_errno == 5)
		printf("The map is not surrounded by walls.\n");
	else if (my_errno == 6)
		printf("There must be one starting point on the map.\n");
	else if (my_errno == 7)
		printf("There must be at least one collectible on the map.\n");
	else if (my_errno == 8)
		printf("There must be at least one exit on the map.\n");
	else
		printf("Invalid error no.\n");
	free_all_resources(game);
	exit(my_errno);
}

void	exit_with_clib_error(t_game *game)
{
	if (errno == 0)
		return ;
	printf("Error\n");
	printf("clib error %d: %s\n", errno, strerror(errno));
	free_all_resources(game);
	exit(errno);
}

void	exit_with_mlx_error(int my_errno, t_game *game)
{
	if (game->mlx_error_ignore)
		return ;
	printf("Error\n");
	printf("mlx error %d: ", my_errno);
	if (my_errno == 1)
		printf("Failed to create mlx instance.\n");
	else if (my_errno == 2)
		printf("Failed to load image.\n");
	else if (my_errno == 3)
		printf("Failed to create window.\n");
	else if (my_errno == 4)
		printf("Failed to put image to window.\n");
	else if (my_errno == 5)
		printf("Failed to clear window.\n");
	else if (my_errno == 6)
		printf("Failed to put string.\n");
	else
		printf("Invalid error no.\n");
	free_all_resources(game);
	exit(my_errno);
}
