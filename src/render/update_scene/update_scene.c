/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:54:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 03:32:46 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"

void	update_scene(t_scene *scene)
{
	int					i;
	const t_update_obj	update_obj[] = {
		update_sphere,
		update_plane,
		update_cylinder,
		update_triangle,
		update_hyperbol
	};
	t_obj_tag			tag;

	i = 0;
	while (i < scene->nb_cameras)
	{
		update_camera(scene, scene->camera + i);
		i++;
	}
	i = 0;
	while (i < scene->nb_objs)
	{
		tag = scene->obj[i].tag;
		(*update_obj[tag])(scene->obj + i, scene->camera);
		i++;
	}
}
