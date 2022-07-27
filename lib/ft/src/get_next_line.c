/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:58:05 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:24:11 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*str_buff_join(char *str, char *buff, unsigned int size)
{
	char			*new_str;
	size_t			len_str;
	size_t			i;

	len_str = 0;
	while (str && str[len_str])
		len_str++;
	new_str = malloc(len_str + size + 1);
	i = 0;
	while (new_str && str && i < len_str)
	{
		new_str[i] = str[i];
		i++;
	}
	i = 0;
	while (new_str && buff && i < size)
	{
		new_str[len_str + i] = buff[i];
		i++;
	}
	if (str)
		free(str);
	if (new_str)
		new_str[len_str + i] = 0;
	return (new_str);
}

static int	update_line(char **line, char *buffer, int *r_size,
	unsigned int *i_buffer)
{
	int	i;
	int	end_of_line;

	if (*r_size == -1)
	{
		free(*line);
		*line = 0;
		*i_buffer = 0;
	}
	if (*r_size == 0 || *r_size == -1)
		return (-1);
	i = *i_buffer;
	while (i < *r_size && buffer[i] != '\n')
		i++;
	end_of_line = (i < *r_size);
	if (end_of_line)
		i++;
	*line = str_buff_join(*line, buffer + *i_buffer, i - *i_buffer);
	if (i < *r_size)
		*i_buffer = i;
	else
		*i_buffer = 0;
	if (end_of_line)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	char				*line;
	static char			buffer[BUFFER_SIZE] = "";
	static unsigned int	i_buffer = 0;
	static int			read_size;

	if (fd < 0 || fd >= 1024)
		return (0);
	if (i_buffer == 0)
		read_size = read(fd, buffer, BUFFER_SIZE);
	line = 0;
	while (update_line(&line, buffer, &read_size, &i_buffer) != -1)
		read_size = read(fd, buffer, BUFFER_SIZE);
	return (line);
}
