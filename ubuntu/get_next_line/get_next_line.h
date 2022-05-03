/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:30 by younglee          #+#    #+#             */
/*   Updated: 2022/05/03 16:05:59 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>

# define BUFFER_SIZE 10
# define HASH_SIZE 50
# define DATA_SIZE 100

typedef struct s_lst
{
	char			*data;
	size_t			data_size;
	size_t			data_back;
	int				fd;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

char	*get_next_line(int fd);

t_lst	*make_new_lst(t_lst *prev, int fd);
int		my_strncpy(t_lst *list, char *buffer, ssize_t copy_count);
int		refresh_data(t_lst *list, char *buf, ssize_t n_l_idx, ssize_t rd_cnt);
void	clear_lst(t_lst *list);

#endif
