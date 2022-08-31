/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:43:55 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/31 15:52:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "init.h"
#include "scene.h"
#include "t_math.h"

static int	control_cam_lights(t_scene *scene)
{
	int	i;

	if (scene->nb_cameras <= 0)
		return (-1);
	i = -1;
	while (++i < scene->nb_cameras)
	{
		if (v_norm(scene->camera[i].dir) == 0)
			return (-1);
	}
	if (scene->nb_ambient_lights <= 0 || scene->nb_lights <= 0)
		return (-1);
	return (0);
}

static int	control_objs(t_scene *scene)
{
	int			i;
	t_obj_tag	tag;

	if (scene->nb_objs <= 0)
		return (-1);
	i = -1;
	while (++i < scene->nb_objs)
	{
		tag = scene->obj[i].tag;
		if (tag == plane_tag || tag == cylinder_tag || tag == hyperbol_tag)
		{
			if (v_norm(scene->obj[i].cylinder.dir) == 0.0f)
				return (-1);
		}
	}
	return (0);
}

int	control_scene(t_scene *scene)
{
	if (control_cam_lights(scene))
		return (-1);
	if (control_objs(scene))
		return (-1);
	return (0);
}
