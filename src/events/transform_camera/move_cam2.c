/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:26:51 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "events.h"
#include "t_math.h"

int	move_cam_backward(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-1, camera->dir));
	return (0);
}
