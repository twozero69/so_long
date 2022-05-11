# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:39:24 by younglee          #+#    #+#              #
#    Updated: 2022/05/11 23:49:36 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
INC			= -I./includes
M_SRCS		= srcs/main.c \
			srcs/error.c \
			srcs/map.c \
			srcs/map_utils.c \
			srcs/free.c \
			srcs/load.c \
			srcs/hook.c \
			srcs/hook_utils.c \
			srcs/render.c
M_OBJS		= ${M_SRCS:.c=.o}
B_SRCS		= bonus/main_bonus.c \
			bonus/error_bonus.c \
			bonus/map_bonus.c \
			bonus/map_utils_bonus.c \
			bonus/free_bonus.c \
			bonus/load_bonus.c \
			bonus/hook_bonus.c \
			bonus/hook_utils_bonus.c \
			bonus/render_bonus.c \
			bonus/enemy_bonus.c
B_OBJS		= ${B_SRCS:.c=.o}
RM			= @rm -f

GNL_SRCS	= get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS	= ${GNL_SRCS:.c=.o}
GNL_INC		= -I./get_next_line

LIBFT		= -L./libft -lft
LIBFT_LIB	= libft/libft.a
LIBFT_INC	= -I./libft
LIBFT_DIR	= libft

KERNEL		:= ${shell uname -s}
ifeq (${KERNEL}, Darwin)
	MLX		= -L./minilibx-apple -lmlx -framework OpenGL -framework AppKit
	MLX_LIB	= minilibx-apple/libmlx.a
	MLX_INC	= -I./minilibx-apple
	MLX_DIR = minilibx-apple
endif
ifeq (${KERNEL}, Linux)
	MLX		= -L./minilibx-linux -lmlx -lXext -lX11 -lm
	MLX_LIB	= minilibx-linux/libmlx.a
	MLX_INC	= -I./minilibx-linux
	MLX_DIR = minilibx-linux
endif

ifndef WITH_BONUS
	OBJS	= ${M_OBJS}
	TRASH	= ${B_OBJS}
else
	OBJS	= ${B_OBJS}
	TRASH	= ${M_OBJS}
endif


.c.o:
			${CC} ${CFLAGS} ${INC} ${GNL_INC} ${LIBFT_INC} ${MLX_INC} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} ${GNL_OBJS} ${LIBFT_LIB} ${MLX_LIB}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${GNL_OBJS} ${LIBFT} ${MLX}
			${RM} ${TRASH}

all:		${NAME}

${LIBFT_LIB}:
			@make bonus -C ${LIBFT_DIR}

${MLX_LIB}:
			@make -C ${MLX_DIR}

clean:
			${RM} ${M_OBJS} ${B_OBJS} ${GNL_OBJS}
			@make clean -C ${LIBFT_DIR}
			@make clean -C ${MLX_DIR}

fclean:		clean
			${RM} ${NAME} ${LIBFT_LIB} ${MLX_LIB}

re:			fclean all

bonus:
			@make WITH_BONUS=1 all

.PHONY:		.c.o clean fclean re bonus
