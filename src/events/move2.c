/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/03 22:41:29 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"

int	move_backward(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-1, camera->dir));
	return (0);
}
