/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:09:58 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 22:21:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "ft.h"
#include "mask.h"
#include "minirt.h"
#include "scene.h"
#include "t_math.h"

static void	update_camera_anchor(t_camera *camera)
{
	float	dist_to_screen;
	float	x_offset;
	float	y_offset;

	dist_to_screen = (float)(WIDTH / 2) / tanf(camera->fov * M_PI / 360);
	camera->anchor = v_scalar(dist_to_screen, camera->dir);
	x_offset = (float)(WIDTH - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(x_offset, camera->ux));
	y_offset = (float)(HEIGHT - 1) / 2;
	camera->anchor = v_sub(camera->anchor, v_scalar(-y_offset, camera->uy));
}

int	update_camera(t_camera *camera, t_scene *scene)
{
	camera->ux = v_cross_product(camera->dir, camera->rot_axis);
	if (v_norm2(camera->ux) < 0.0005)
		camera->ux = (t_vect){1, 0, 0};
	camera->uy = v_cross_product(camera->ux, camera->dir);
	v_normalize(&camera->uy);
	camera->ux = v_cross_product(camera->dir, camera->uy);
	v_normalize(&camera->ux);
	update_camera_anchor(camera);
	update_masks_camera(camera, scene);
	return (0);
}
