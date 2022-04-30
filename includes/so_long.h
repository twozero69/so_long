/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:48:39 by younglee          #+#    #+#             */
/*   Updated: 2022/04/30 17:03:47 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FALSE 0
# define TRUE 1
# ifndef NULL
#  define NULL 0
# endif

# define IMG_SIZE 64
# define SPRITE_NUM 4

# ifdef __APPLE__
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define ESC_KEY 53
# elif	__linux__
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define ESC_KEY 65307
# endif

# define KEYPRESS 2
# define KEYPRESSMASK 0x1L
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK 0x20000L

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
	void		*mlx;
	void		*window;
	void		*space_image;
	void		*wall_image;
	void		*exit_close_image;
	void		*exit_open_image;
	void		*collectible_image;
	void		*enemy_image[SPRITE_NUM];
	void		*character_image[SPRITE_NUM];
	int			frame_count;
	int			move_flag;
	int			move_count;
}t_game;

//error.c
void	exit_with_custom_error(int my_errno, t_game *game);
void	exit_with_clib_error(t_game *game);
void	exit_with_mlx_error(int my_errno, t_game *game);

//map.c
void	check_map(char *file, t_game *game);

//map_utils.c
void	check_argc(int argc, t_game *game);
void	check_char(char c, t_game *game);
void	check_wall(int row, int col, char c, t_game *game);
void	check_start(int row, int col, t_game *game);
void	check_token(t_game *game);

//free.c
void	free_all_resources(t_game *game);

//load.c
void	load_images(t_game *game);

//hook.c
int		key_hook(int keycode, t_game *game);
int		exit_hook(t_game *game);
int		loop_hook(t_game *game);

#endif
