/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:41:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/31 13:43:35 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"
#include "scene.h"
#include "terminate.h"

static int	set_elem_any_type(t_scene *scene, char **elem,
	int *i_elem_category)
{
	static char	*rt_elem[] = {RT_AMBIENT_LIGHT, RT_CAMERA, RT_LIGHT,
		RT_SPHERE, RT_PLANE, RT_CYLINDER, RT_TRIANGLE, RT_HYPERBOL, RT_TEXTURE,
		RT_BUMPMAP, NULL};
	static int	(*rt_set_elem[])(t_scene *, char **, int *) = {
		rt_set_ambient_light, rt_set_camera, rt_set_light, rt_set_sphere,
		rt_set_plane, rt_set_cylinder, rt_set_triangle, rt_set_hyperbol,
		rt_set_texture, rt_set_bumpmap};
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
	if (alloc_scene(scene, scene_lines) == -1)
		return (ft_putstr_fd("Error malloc scene\n", 2), -1);
	if (set_scene(scene, scene_lines) == -1)
		return (free_scene(scene), ft_putstr_fd("Error set scene\n", 2), -1);
	if (control_scene(scene) == -1)
		return (free_scene(scene), ft_putstr_fd("Error set scene\n", 2), -1);
	return (0);
}
