# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:39:24 by younglee          #+#    #+#              #
#    Updated: 2022/04/29 22:28:02 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INC			= -I./includes
SRCS		= srcs/main.c \
			srcs/error.c \
			srcs/map.c \
			srcs/map_utils.c \
			srcs/game.c \
			srcs/free.c \
			srcs/load.c
OBJS		= ${SRCS:.c=.o}
RM			= rm -f
GNL_SRCS	= get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS	= ${GNL_SRCS:.c=.o}
GNL_INC		= -I./get_next_line
LIBFT		= -L./libft -lft
LIBFT_LIB	= libft/libft.a
LIBFT_INC	= -I./libft
MLX			= -L./mlx -lmlx_Linux -lXext -lX11 -lm
# MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit
MLX_LIB		= mlx/libmlx_Linux.a
MLX_INC		= -I./mlx

.c.o:
			${CC} ${CFLAGS} ${INC} ${GNL_INC} ${LIBFT_INC} ${MLX_INC} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} ${GNL_OBJS} ${LIBFT_LIB} ${MLX_LIB}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${GNL_OBJS} ${LIBFT} ${MLX}

all:		${NAME}

${LIBFT_LIB}:
			make bonus -C libft

${MLX_LIB}:
			make -C mlx

clean:
			${RM} ${OBJS} ${GNL_OBJS}
			make clean -C libft
			make clean -C mlx

fclean:		clean
			${RM} ${NAME} ${LIBFT_LIB} ${MLX_LIB}

re:			fclean all

.PHONY:		.c.o clean fclean re
