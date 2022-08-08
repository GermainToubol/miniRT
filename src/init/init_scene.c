/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:23:33 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 19:05:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"
#include "init.h"
#include "minirt.h"

static int	is_empty(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

static int	set_scene_lines(char ***scene_lines, int argc, char **argv)
{
	int		fd;
	char	*line;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("miniRT"), -1);
	*scene_lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty(line))
			free(line);
		else if (ft_strs_append(scene_lines, line) == -1)
			return (close(fd), ft_free_tab(*scene_lines), free(line), -1);
		line = get_next_line(fd);
	}
	close(fd);
	if (!*scene_lines)
		return (-1);
	return (0);
}

int	init_scene(t_scene *scene, int argc, char **argv)
{
	char	**scene_lines;
	int		ret_value;

	if (set_scene_lines(&scene_lines, argc, argv) == -1)
		return (ft_putstr_fd("Error while reading input file\n", 2), -1);
	ret_value = check_scene(scene_lines);
	if (ret_value != 0)
		return (ft_free_tab(scene_lines), ret_value);
	if (parse_scene(scene, scene_lines) == -1)
		return (ft_free_tab(scene_lines), 1);
	ft_free_tab(scene_lines);
	name_scene_elems(scene);
	init_scene_derivates(scene);
	return (0);
}
