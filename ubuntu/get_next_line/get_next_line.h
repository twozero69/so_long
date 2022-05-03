/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:30 by younglee          #+#    #+#             */
/*   Updated: 2022/03/25 22:48:13 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>

# define HASH_SIZE 50
# define DATA_SIZE 100

typedef struct s_list
{
	char			*data;
	size_t			data_size;
	size_t			data_back;
	int				fd;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

char	*get_next_line(int fd);

t_list	*make_new_list(t_list *prev, int fd);
int		my_strncpy(t_list *list, char *buffer, ssize_t copy_count);
int		refresh_data(t_list *list, char *buf, ssize_t n_l_idx, ssize_t rd_cnt);
void	clear_list(t_list *list);

#endif
