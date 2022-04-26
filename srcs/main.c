/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:46:11 by younglee          #+#    #+#             */
/*   Updated: 2022/04/26 23:40:00 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_argc(argc))
		return (0);
	parse_map(argv[1], &game);
	if (check_map(&game))
		return (0);
}
