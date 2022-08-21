/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:54:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 18:55:31 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"

void	update_scene(t_scene *scene)
{
	const t_update_obj	update_obj[] = {
		update_sphere,
		update_plane,
		update_cylinder,
		update_triangle,
		update_hyperbol
	};
	t_obj_tag			tag;
	int					i;

	i = -1;
	while (++i < scene->nb_cameras)
		update_camera(scene->camera + i, scene);
	i = -1;
	while (++i < scene->nb_lights)
		update_light(scene->light + i, scene);
	i = -1;
	while (++i < scene->nb_objs)
	{
		tag = scene->obj[i].tag;
		(*update_obj[tag])(scene->obj + i, scene->camera);
	}
}
