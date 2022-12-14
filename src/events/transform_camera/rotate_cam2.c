/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:19:19 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 19:43:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "scene.h"
#include "t_math.h"

int	rotate_cam_reverse_yaw(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	v_rotate(&camera->dir, camera->rot_axis, -M_PI / 12);
	data->ui_state.to_render = 1;
	return (0);
}
