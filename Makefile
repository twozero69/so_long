# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:39:24 by younglee          #+#    #+#              #
#    Updated: 2022/04/28 11:53:03 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INC			= -I./includes
SRCS		= srcs/main.c \
			srcs/error.c \
			srcs/map.c \
			srcs/map_utils.c
OBJS		= ${SRCS:.c=.o}
RM			= rm -f
GNL_SRCS	= get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
GNL_OBJS	= ${GNL_SRCS:.c=.o}
GNL_INC		= -I./get_next_line
LIBFT		= -L./libft -lft
LIBFT_A		= libft/libft.a
LIBFT_INC	= -I./libft

.c.o:
			${CC} ${CFLAGS} ${INC} ${GNL_INC} ${LIBFT_INC} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} ${GNL_OBJS} ${LIBFT_A}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${GNL_OBJS} ${LIBFT}

all:		${NAME}

${LIBFT_A}:
			make bonus -C libft

clean:
			${RM} ${OBJS} ${GNL_OBJS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			${RM} libft/libft.a

re:			fclean all

.PHONY:		.c.o clean fclean re
