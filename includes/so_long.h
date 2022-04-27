/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:48:39 by younglee          #+#    #+#             */
/*   Updated: 2022/04/27 18:48:59 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FALSE 0
# define TRUE 1
# define NULL 0

typedef struct s_position
{
	int		row;
	int		col;
}t_position;

typedef struct s_game
{
	int			fd;
	int			width;
	int			height;
	char		**map;
	int			collectible;
	int			exit;
	t_position	position;
}t_game;

//error.c
void	exit_with_custom_error(int my_errno, t_game *game);
void	exit_with_clib_error(t_game *game);

//map.c
void	check_map(char *file, t_game *game);

//map_utils.c
void	check_argc(int argc, t_game *game);
void	check_char(char c, t_game *game);
void	check_wall(int row, int col, char c, t_game *game);
void	check_start(int row, int col, t_game *game);
void	check_token(t_game *game);

#endif
