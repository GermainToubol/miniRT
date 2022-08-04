/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:50:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 00:19:12 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "t_math.h"

int	rotate_roll(t_data *data)
{
	t_camera	*camera;
	t_dir		anchor_dir;

	camera = data->scene.camera;
	v_rotate(&camera->ux, camera->dir, M_PI / 12);
	v_rotate(&camera->uy, camera->dir, M_PI / 12);
	anchor_dir = v_sub(camera->anchor, camera->pos);
	v_rotate(&anchor_dir, camera->dir, M_PI / 12);
	camera->anchor = v_add(camera->pos, anchor_dir);
	return (0);
}

int	rotate_roll_reverse(t_data *data)
{
	t_camera	*camera;
	t_dir		anchor_dir;

	camera = data->scene.camera;
	v_rotate(&camera->ux, camera->dir, -M_PI / 12);
	v_rotate(&camera->uy, camera->dir, -M_PI / 12);
	anchor_dir = v_sub(camera->anchor, camera->pos);
	v_rotate(&anchor_dir, camera->dir, -M_PI / 12);
	camera->anchor = v_add(camera->pos, anchor_dir);
	return (0);
}

int	rotate_pitch(t_data *data)
{
	t_camera	*camera;
	t_dir		anchor_dir;

	camera = data->scene.camera;
	v_rotate(&camera->dir, camera->ux, M_PI / 12);
	v_rotate(&camera->uy, camera->ux, M_PI / 12);
	anchor_dir = v_sub(camera->anchor, camera->pos);
	v_rotate(&anchor_dir, camera->ux, M_PI / 12);
	camera->anchor = v_add(camera->pos, anchor_dir);
	return (0);
}

int	rotate_pitch_reverse(t_data *data)
{
	t_camera	*camera;
	t_dir		anchor_dir;

	camera = data->scene.camera;
	v_rotate(&camera->dir, camera->ux, -M_PI / 12);
	v_rotate(&camera->uy, camera->ux, -M_PI / 12);
	anchor_dir = v_sub(camera->anchor, camera->pos);
	v_rotate(&anchor_dir, camera->ux, -M_PI / 12);
	camera->anchor = v_add(camera->pos, anchor_dir);
	return (0);
}

int	rotate_yaw(t_data *data)
{
	t_camera	*camera;
	t_dir		anchor_dir;

	camera = data->scene.camera;
	v_rotate(&camera->dir, camera->uy, M_PI / 12);
	v_rotate(&camera->ux, camera->uy, M_PI / 12);
	anchor_dir = v_sub(camera->anchor, camera->pos);
	v_rotate(&anchor_dir, camera->uy, M_PI / 12);
	camera->anchor = v_add(camera->pos, anchor_dir);
	return (0);
}
