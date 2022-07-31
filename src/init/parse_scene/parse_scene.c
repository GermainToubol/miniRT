/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:41:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 20:27:33 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "init.h"
#include "scene.h"
#include "terminate.h"

#include <stdio.h>

static void	count_nb_elem_category(int *nb_elem_category, char **scene_lines)
{
	const char	*rt_elem_category[3][4] = {{RT_SPHERE, RT_PLANE, RT_CYLINDER,
		NULL}, {RT_LIGHT, NULL}, {RT_CAMERA, NULL}};
	char		*rt_elem;
	int			i;
	int			j;

	ft_memset_int(nb_elem_category, 0, 3);
	while (*scene_lines)
	{
		i = 0;
		while (i < 3)
		{
			j = 0;
			while (rt_elem_category[i][j])
			{
				rt_elem = (char *) rt_elem_category[i][j];
				if (ft_strncmp(*scene_lines, rt_elem, ft_strlen(rt_elem)) == 0)
					nb_elem_category[i]++;
				j++;
			}
			i++;
		}
		scene_lines++;
	}
}

static int	malloc_scene(t_scene *scene, char **scene_lines)
{
	int	nb_elem_category[3];

	count_nb_elem_category(nb_elem_category, scene_lines);
	scene->nb_objs = nb_elem_category[0];
	scene->obj = malloc(sizeof(t_obj) * scene->nb_objs);
	if (!scene->obj)
		return (-1);
	scene->nb_lights = nb_elem_category[1];
	scene->light = malloc(sizeof(t_light) * scene->nb_lights);
	if (!scene->light)
		return (free(scene->obj), -1);
	scene->nb_cameras = nb_elem_category[2];
	scene->camera = malloc(sizeof(t_camera) * scene->nb_cameras);
	if (!scene->camera)
		return (free(scene->obj), free(scene->light), -1);
	return (0);
}

static int	set_elem_any_type(t_scene *scene, char **elem,
	int *i_elem_category)
{
	const char			*rt_elem[] = {RT_AMBIENT_LIGHT, RT_CAMERA, RT_LIGHT,
		RT_SPHERE, RT_PLANE, RT_CYLINDER, NULL};
	const t_rt_set_elem	rt_set_elem[] = {rt_set_ambient_light, rt_set_camera,
		rt_set_light, rt_set_sphere, rt_set_plane, rt_set_cylinder};
	int					i;

	i = 0;
	while (rt_elem[i])
	{
		if (ft_strcmp(elem[0], rt_elem[i]) == 0)
			return ((rt_set_elem[i])(scene, elem, i_elem_category));
		i++;
	}
	return (-1);
}

static int	set_scene(t_scene *scene, char **scene_lines)
{
	int		i_elem_category[3];
	char	**elem;

	ft_memset_int(i_elem_category, 0, 3);
	while (*scene_lines)
	{
		elem = ft_split(*scene_lines, " \n");
		if (!elem)
			return (-1);
		if (set_elem_any_type(scene, elem, i_elem_category) == -1)
			return (ft_free_tab(elem), -1);
		ft_free_tab(elem);
		scene_lines++;
	}
	return (0);
}

int	parse_scene(t_scene *scene, char **scene_lines)
{
	printf("bonjour1\n");
	if (malloc_scene(scene, scene_lines) == -1)
		return (ft_putstr_fd("Error malloc scene\n", 2), -1);
	printf("bonjour2\n");
	if (set_scene(scene, scene_lines) == -1)
		return (free_scene(scene), ft_putstr_fd("Error set scene\n", 2), -1);
	printf("bonjour3\n");
	return (0);
}
