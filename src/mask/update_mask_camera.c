/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mask_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:30:29 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 13:51:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raster.h"
#include "scene.h"

void	update_mask_camera(t_obj *obj, t_camera *camera, int n)
{
	const t_mask_func	init_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_cylinder_mask,
		set_default_mask
	};
	t_light				light;

	light = (t_light){"", camera->pos, 0, {0, 0, 0}, 0};
	(*init_mask[obj[n].tag])(obj + n, &light, camera->mask + n);
	camera->mask[n].dir = v_scalar(-1.0f, camera->mask[n].dir);
}

void	update_masks_camera(t_scene *scene, t_camera *camera)
{
	int	i;

	i = -1;
	while (++i < scene->nb_objs)
		update_mask_camera(scene->obj, camera, i);
}
