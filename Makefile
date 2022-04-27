# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:39:24 by younglee          #+#    #+#              #
#    Updated: 2022/04/27 23:44:44 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
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
GNL_INC		= get_next_line/get_next_line.h
LIBFT		= libft/libft.a

.c.o:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

libft:
			@make -C libft

${NAME}: 	${OBJS} ${GNL_OBJS} libft
			${CC} -o ${NAME} ${OBJS} ${GNL_OBJS} -L./libft -lft

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		.c.o clean fclean re libft
