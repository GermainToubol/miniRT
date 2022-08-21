/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollmove_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:09:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 18:46:08 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "scene.h"
#include "t_math.h"

int	rollmove_cam_forward(int mouse_x, int mouse_y, t_data *data)
{
	t_camera	*camera;
	t_ray		ray;

	camera = data->scene.camera;
	set_ray(&ray, camera, mouse_x, mouse_y);
	camera->pos = v_add(camera->pos, ray.dir);
	data->ui_state.to_render = 1;
	return (0);
}

int	rollmove_cam_backward(int mouse_x, int mouse_y, t_data *data)
{
	t_camera	*camera;
	t_ray		ray;

	camera = data->scene.camera;
	set_ray(&ray, camera, mouse_x, mouse_y);
	camera->pos = v_sub(camera->pos, ray.dir);
	data->ui_state.to_render = 1;
	return (0);
}
