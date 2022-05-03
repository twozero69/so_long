/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:20:46 by younglee          #+#    #+#             */
/*   Updated: 2022/05/03 16:05:27 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

t_lst	*make_new_lst(t_lst *prev, int fd)
{
	t_lst	*new_lst;

	new_lst = (t_lst *)malloc(sizeof(t_lst));
	if (new_lst == 0)
		return (0);
	new_lst->data = (char *)malloc(DATA_SIZE * sizeof(char));
	if (new_lst->data == 0)
	{
		free(new_lst);
		return (0);
	}
	new_lst->data[0] = '\0';
	new_lst->data_size = DATA_SIZE;
	new_lst->data_back = 0;
	new_lst->fd = fd;
	new_lst->next = 0;
	new_lst->prev = prev;
	return (new_lst);
}

static int	extend_data(t_lst *list, ssize_t copy_count)
{
	char	*new_data;
	size_t	new_size;
	size_t	idx;

	if (list->data_size >= list->data_back + copy_count + 1)
		return (1);
	if (copy_count > DATA_SIZE)
		new_size = list->data_back + copy_count + 1;
	else
		new_size = list->data_size * 2;
	new_data = (char *)malloc(new_size * sizeof(char));
	if (new_data == 0)
		return (0);
	idx = 0;
	while (idx < list->data_back)
	{
		new_data[idx] = list->data[idx];
		idx++;
	}
	new_data[list->data_back] = '\0';
	free(list->data);
	list->data = new_data;
	list->data_size = new_size;
	return (1);
}

int	my_strncpy(t_lst *list, char *buffer, ssize_t copy_count)
{
	ssize_t	idx;

	if (extend_data(list, copy_count) == 0)
		return (0);
	idx = 0;
	while (idx < copy_count)
	{
		list->data[list->data_back] = buffer[idx];
		list->data_back++;
		idx++;
	}
	list->data[list->data_back] = '\0';
	return (1);
}

int	refresh_data(t_lst *list, char *data, ssize_t n_l_idx, ssize_t rd_cnt)
{
	list->data = (char *)malloc(DATA_SIZE * sizeof(char));
	if (list->data == 0)
		return (0);
	list->data[0] = '\0';
	list->data_size = DATA_SIZE;
	list->data_back = 0;
	if (n_l_idx == -1)
		return (1);
	if (my_strncpy(list, &data[n_l_idx + 1], rd_cnt - n_l_idx - 1) == 0)
	{
		free(list->data);
		list->data = data;
		return (0);
	}
	return (1);
}

void	clear_lst(t_lst *list)
{
	t_lst	*prev;
	t_lst	*next;

	prev = list->prev;
	next = list->next;
	prev->next = next;
	if (next != 0)
		next->prev = prev;
	free(list->data);
	free(list);
}
