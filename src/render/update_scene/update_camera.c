/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:09:58 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 17:42:44 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "ft.h"
#include "mask.h"
#include "minirt.h"
#include "scene.h"
#include "t_math.h"

int	update_camera(t_scene *scene, t_camera *camera)
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
	update_masks_camera(camera, scene);
	return (0);
}
