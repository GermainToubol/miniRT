/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:50:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 22:27:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "scene.h"
#include "t_math.h"

int	rotate_cam_roll(t_data *data)
{
	t_camera	*camera;
	t_vect		proj;

	camera = data->scene.camera;
	proj = v_cross_product(camera->dir, camera->rot_axis);
	v_rotate(&proj, camera->rot_axis, M_PI / 2);
	v_rotate(&camera->rot_axis, proj, M_PI / 12);
	v_normalize(&camera->rot_axis);
	data->ui_state.to_render = 1;
	return (0);
}

int	rotate_cam_reverse_roll(t_data *data)
{
	t_camera	*camera;
	t_vect		proj;

	camera = data->scene.camera;
	proj = v_cross_product(camera->dir, camera->rot_axis);
	v_rotate(&proj, camera->rot_axis, M_PI / 2);
	v_rotate(&camera->rot_axis, proj, -M_PI / 12);
	v_normalize(&camera->rot_axis);
	data->ui_state.to_render = 1;
	return (0);
}

int	rotate_cam_pitch(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	if (v_angle(camera->dir, camera->rot_axis) <= M_PI / 12)
		return (0);
	v_rotate(&camera->dir, camera->ux, M_PI / 12);
	data->ui_state.to_render = 1;
	return (0);
}

int	rotate_cam_reverse_pitch(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	if (v_angle(camera->dir, camera->rot_axis) >= M_PI - M_PI / 12)
		return (0);
	v_rotate(&camera->dir, camera->ux, -M_PI / 12);
	data->ui_state.to_render = 1;
	return (0);
}

int	rotate_cam_yaw(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	v_rotate(&camera->dir, camera->rot_axis, M_PI / 12);
	data->ui_state.to_render = 1;
	return (0);
}
