/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:54:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 19:16:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parameters.h"
#include "scene.h"
#include "t_math.h"

static void	init_camera_derivates(t_camera *camera)
{
	float		dist_to_screen;
	float		x_offset;
	float		y_offset;

	camera->ux.x = camera->dir.y;
	camera->ux.y = -camera->dir.x;
	camera->ux.z = 0;
	v_normalize(&camera->ux);
	camera->uy = v_cross_product(camera->ux, camera->dir);
	dist_to_screen = (float) WIDTH / 2;
	dist_to_screen /= tanf(camera->fov * M_PI / 360);
	camera->anchor = v_scalar(dist_to_screen, camera->dir);
	x_offset = (float)(WIDTH - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(x_offset, camera->ux));
	y_offset = (float)(HEIGHT - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(-y_offset, camera->uy));
}

static void	init_cameras_derivates(t_camera *camera, int nb_cameras)
{
	int			i;

	i = 0;
	while (i < nb_cameras)
	{
		init_camera_derivates(camera + i);
		i++;
	}
}

static void	init_triangles_derivates(t_obj *obj, int nb_objs)
{
	t_triangle	*triangle;
	int			i;

	i = 0;
	while (i < nb_objs)
	{
		if (obj[i].tag == triangle_tag)
		{
			triangle = &obj[i].triangle;
			triangle->normal = v_cross_product(
					v_sub(triangle->edge[0], triangle->edge[1]),
					v_sub(triangle->edge[0], triangle->edge[2]));
			v_normalize(&triangle->normal);
		}
		i++;
	}
}

void	init_scene_derivates(t_scene *scene)
{
	init_cameras_derivates(scene->camera, scene->nb_cameras);
	init_triangles_derivates(scene->obj, scene->nb_objs);
}
