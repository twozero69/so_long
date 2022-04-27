/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:29:49 by younglee          #+#    #+#             */
/*   Updated: 2022/04/27 18:49:19 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft.h"

static void	open_map(char *file, t_game *game)
{
	game->fd = open(file, O_RDONLY);
	exit_with_clib_error(game);
}

static void	close_map(t_game *game)
{
	if (game->fd == -1)
		return ;
	close(game->fd);
	exit_with_clib_error(game);
	game->fd = -1;
}

static void	check_height(char *file, t_game *game)
{
	int		line_count;
	char	*line;
	int		idx;

	open_map(file, &map, game);
	line_count = 0;
	while (TRUE)
	{
		line = get_next_line(game->fd);
		exit_with_clib_error(game);
		if (line == NULL)
			break ;
		free(line);
		line_count++;
	}
	close_map(game);
	game->map = (char **)malloc((line_count + 1) * sizeof(char));
	exit_with_clib_error(game);
	idx = 0;
	while (idx <= line_count)
	{
		game->map[idx] = NULL;
		idx++;
	}
	game->height = line_count;
}

static void	check_width(char *file, t_game *game)
{
	int		line_count;
	size_t	line_length;
	char	*line;

	open_map(file, &map, game);
	line_count = 0;
	while (TRUE)
	{
		game->map[line_count] = get_next_line(game->fd);
		exit_with_clib_error(game);
		if (line == NULL)
			break ;
		line_count++;
		line_length = ft_strlen(game->map[line_count]);
		if (map->width == 0)
			map->width = line_length;
		if (map->width != line_length)
			exit_with_custom_error(3, game);
	}
	close_map(game);
}

void	check_map(char *file, t_game *game)
{
	int		row;
	int		col;

	check_height(file, game);
	check_width(file, game);
	row = 0;
	col = 0;
	while (row < game->height)
	{
		while (col < game->width)
		{
			check_char(game->map[row][col], game);
			check_wall(row, col, game->map[row][col], game);
			if (game->map[row][col] == 'C')
				game->collectible++;
			if (game->map[row][col] == 'E')
				game->exit++;
			if (game->map[row][col] == 'P')
				check_start(row, col, game);
			col++;
		}
		row++;
	}
	check_token(game);
}
