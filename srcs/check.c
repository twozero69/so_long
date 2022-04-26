/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:35:27 by younglee          #+#    #+#             */
/*   Updated: 2022/04/26 23:51:30 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argc(int argc)
{
	if (argc != 2)
	{
		argc_error(argc);
		return (FALSE);
	}
	return (TRUE);
}

int	check_map(t_game *game)
{
	return (TRUE);
}
