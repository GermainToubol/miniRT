/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mask_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:30:29 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 11:56:02 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask.h"
#include "scene.h"

void	update_mask_camera(t_mask *mask, t_camera *camera,
	t_obj *obj)
{
	const t_mask_func	set_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_cylinder_mask,
		set_triangle_mask,
		set_hyperbol_mask
	};

	(*set_mask[obj->tag])(mask, obj, &camera->pos);
}

void	update_masks_camera(t_camera *camera, t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_objs)
		update_mask_camera(camera->mask + i, camera, scene->obj + i);
}

void	update_mask_cameras(t_scene *scene, int n)
{
	int	i;

	i = -1;
	while (++i < scene->nb_cameras)
		update_mask_camera(scene->camera[i].mask + n, scene->camera + i,
			scene->obj + n);
}

void	update_masks_cameras(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_cameras)
		update_masks_camera(scene->camera + i, scene);
}
