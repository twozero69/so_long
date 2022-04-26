/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:48:39 by younglee          #+#    #+#             */
/*   Updated: 2022/04/26 23:34:56 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FALSE 0
# define TRUE 1

typedef struct s_game
{
	int		width;
	int		height;
	char	**map;
}t_game;

//error.c
void	argc_error(int argc);

//map.c
void	parse_map(char *file, t_game *game);

#endif
