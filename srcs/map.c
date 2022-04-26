/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:29:49 by younglee          #+#    #+#             */
/*   Updated: 2022/04/26 23:58:43 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	parse_map(char *file, t_game *game)
{
	int	fd;
	int	line_count;

	fd = open(file, O_RDONLY);
	while (get_next_line)
	{

	}
}
