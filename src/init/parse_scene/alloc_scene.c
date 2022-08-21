/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:04:12 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 15:29:22 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"
#include "scene.h"
#include "terminate.h"

static void	count_nb_elem_category(int *nb_elem_category, char **scene_lines)
{
	static char	*rt_elem_category[6][6] = {{RT_SPHERE, RT_PLANE, RT_CYLINDER,
		RT_TRIANGLE, RT_HYPERBOL, NULL}, {RT_LIGHT, NULL},
	{RT_AMBIENT_LIGHT, NULL}, {RT_CAMERA, NULL}, {RT_TEXTURE, NULL},
	{RT_BUMPMAP, NULL}};
	int			i;
	int			j;

	ft_memset_int(nb_elem_category, 0, 6);
	while (*scene_lines)
	{
		i = 0;
		while (i < 5)
		{
			j = 0;
			while (rt_elem_category[i][j])
			{
				if (ft_strncmp(*scene_lines, rt_elem_category[i][j],
						ft_strlen(rt_elem_category[i][j])) == 0)
					nb_elem_category[i]++;
				j++;
			}
			i++;
		}
		scene_lines++;
	}
}

static int	alloc_elements(t_scene *scene, char **scene_lines)
{
	int	nb_elem_category[6];

	count_nb_elem_category(nb_elem_category, scene_lines);
	scene->nb_objs = nb_elem_category[0];
	scene->obj = ft_calloc(scene->nb_objs, sizeof(t_obj));
	scene->nb_lights = nb_elem_category[1];
	scene->light = ft_calloc(scene->nb_lights, sizeof(t_light));
	scene->nb_ambient_lights = nb_elem_category[2];
	scene->ambient_light = ft_calloc(scene->nb_ambient_lights,
			sizeof(t_ambient_light));
	scene->nb_cameras = nb_elem_category[3];
	scene->camera = ft_calloc(scene->nb_cameras, sizeof(t_camera));
	scene->nb_textures = nb_elem_category[4];
	scene->texture = ft_calloc(scene->nb_textures, sizeof(t_texture));
	scene->nb_bumpmaps = nb_elem_category[5];
	scene->bumpmap = ft_calloc(scene->nb_bumpmaps, sizeof(t_bumpmap));
	if (!scene->obj || !scene->light || !scene->ambient_light || !scene->camera
		|| !scene->texture || !scene->bumpmap)
		return (-1);
	return (0);
}

static int	alloc_masks(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->nb_cameras)
	{
		scene->camera[i].mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
		if (!scene->camera[i].mask)
			return (-1);
		i++;
	}
	i = 0;
	while (i < scene->nb_lights)
	{
		scene->light[i].mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
		if (!scene->light[i].mask)
			return (-1);
		i++;
	}
	return (0);
}

int	alloc_scene(t_scene *scene, char **scene_lines)
{
	if (alloc_elements(scene, scene_lines) == -1
		|| alloc_masks(scene) == -1)
		return (free_scene(scene), -1);
	return (0);
}
