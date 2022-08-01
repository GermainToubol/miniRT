/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:54:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 08:36:10 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"

static void	init_camera_derivates(t_camera *camera)
{
	float		dist_to_screen;
	float		x_offset;
	float		y_offset;

	camera->ux.x = camera->dir.y;
	camera->ux.y = -camera->dir.x;
	camera->ux.z = 0;
	v_normalize(&camera->ux);
	camera->uy = v_cross_product(camera->dir, camera->ux);
	dist_to_screen = (float) WIDTH / 2;
	dist_to_screen /= tanf(camera->fov * 2 * M_PI / 360);
	camera->anchor = v_scalar(dist_to_screen, camera->dir);
	x_offset = (float)(WIDTH - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(x_offset, camera->ux));
	y_offset = (float)(HEIGHT - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(y_offset, camera->uy));
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

void	init_scene_derivates(t_scene *scene)
{
	init_cameras_derivates(scene->camera, scene->nb_cameras);
}
