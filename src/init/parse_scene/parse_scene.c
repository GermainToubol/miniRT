/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:41:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 13:57:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "init.h"
#include "scene.h"
#include "terminate.h"

static void	count_nb_elem_category(int *nb_elem_category, char **scene_lines)
{
	static char	*rt_elem_category[5][5] = {{RT_SPHERE, RT_PLANE, RT_CYLINDER,
		RT_TRIANGLE, NULL}, {RT_LIGHT, NULL}, {RT_CAMERA, NULL},
	{RT_TEXTURE, NULL}, {RT_BUMPMAP, NULL}};
	char		*rt_elem;
	int			i;
	int			j;

	ft_memset_int(nb_elem_category, 0, 5);
	while (*scene_lines)
	{
		i = 0;
		while (i < 5)
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
	int	nb_elem_category[5];

	count_nb_elem_category(nb_elem_category, scene_lines);
	scene->nb_objs = nb_elem_category[0];
	scene->obj = malloc(sizeof(t_obj) * scene->nb_objs);
	scene->nb_lights = nb_elem_category[1];
	scene->light = malloc(sizeof(t_light) * scene->nb_lights);
	scene->nb_ambient_lights = 1;
	scene->ambient_light = malloc(sizeof(t_ambient_light)
			* scene->nb_ambient_lights);
	scene->nb_cameras = nb_elem_category[2];
	scene->camera = malloc(sizeof(t_camera) * scene->nb_cameras);
	scene->nb_textures = nb_elem_category[3];
	scene->texture = malloc(sizeof(t_texture) * scene->nb_textures);
	scene->nb_bumpmaps = nb_elem_category[4];
	scene->bumpmap = malloc(sizeof(t_bumpmap) * scene->nb_bumpmaps);
	if (!scene->obj || !scene->light || !scene->ambient_light || !scene->camera
		|| (scene->nb_textures > 0 && !scene->texture)
		|| (scene->nb_bumpmaps > 0 && !scene->bumpmap))
		return (free_scene(scene), -1);
	ft_memset(scene->texture, 0, scene->nb_textures * sizeof(t_texture));
	ft_memset(scene->bumpmap, 0, scene->nb_bumpmaps * sizeof(t_bumpmap));
	return (0);
}

static int	set_elem_any_type(t_scene *scene, char **elem,
	int *i_elem_category)
{
	static char	*rt_elem[] = {RT_AMBIENT_LIGHT, RT_CAMERA, RT_LIGHT,
		RT_SPHERE, RT_PLANE, RT_CYLINDER, RT_TRIANGLE, RT_TEXTURE, RT_BUMPMAP,
		NULL};
	static int	(*rt_set_elem[])(t_scene *, char **, int *) = {
		rt_set_ambient_light, rt_set_camera, rt_set_light, rt_set_sphere,
		rt_set_plane, rt_set_cylinder, rt_set_triangle, rt_set_texture,
		rt_set_bumpmap};
	int			i;

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
	int		i_elem_category[5];
	char	**elem;

	ft_memset_int(i_elem_category, 0, 5);
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
	if (malloc_scene(scene, scene_lines) == -1)
		return (ft_putstr_fd("Error malloc scene\n", 2), -1);
	if (set_scene(scene, scene_lines) == -1)
		return (free_scene(scene), ft_putstr_fd("Error set scene\n", 2), -1);
	return (0);
}
