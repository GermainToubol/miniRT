/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:54:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 16:04:10 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "derivates.h"
#include "ft.h"
#include "parameters.h"
#include "raster.h"
#include "scene.h"
#include "t_math.h"

static int	init_camera_mask(t_scene *scene, t_camera *camera)
{
	int	i;

	i = -1;
	while (++i < scene->nb_objs)
		update_mask_camera(scene->obj, camera, i);
	return (0);
}

static int	init_camera_derivates(t_scene *scene, t_camera *camera)
{
	float	dist_to_screen;
	float	x_offset;
	float	y_offset;

	if (camera->dir.x == 0)
		camera->ux = (t_dir){1, 0, 0};
	else
		camera->ux = (t_dir){camera->dir.y, -camera->dir.x, 0};
	v_normalize(&camera->ux);
	camera->uy = v_cross_product(camera->ux, camera->dir);
	dist_to_screen = (float) WIDTH / 2;
	dist_to_screen /= tanf(camera->fov * M_PI / 360);
	camera->anchor = v_scalar(dist_to_screen, camera->dir);
	x_offset = (float)(WIDTH - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(x_offset, camera->ux));
	y_offset = (float)(HEIGHT - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(-y_offset, camera->uy));
	return (init_camera_mask(scene, camera));
}

void	init_scene_derivates(t_scene *scene)
{
	int						i;
	const t_derivate_func	derivates[] = {
		init_sphere_derivates,
		init_plane_derivates,
		init_cylinder_derivates,
		init_triangle_derivates};

	i = -1;
	while (++i < scene->nb_cameras)
		init_camera_derivates(scene, scene->camera + i);
	i = -1;
	while (++i < scene->nb_objs)
		(*derivates[scene->obj[i].tag])(scene->obj + i);
}
