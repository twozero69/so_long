/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:54 by younglee          #+#    #+#             */
/*   Updated: 2022/04/26 23:37:30 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	argc_error(int argc)
{
	perror("Error\n");
	if (argc < 2)
		perror("A map must be given as an argument.\n");
	else if (argc > 2)
		perror("Only one map must be given as an argument.\n");
}
