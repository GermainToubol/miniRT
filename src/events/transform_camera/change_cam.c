/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:51:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 17:02:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "scene.h"

int	change_cam(t_data *data)
{
	int			nb_cameras;
	t_camera	*camera;
	t_camera	first_camera;
	int			i;

	nb_cameras = data->scene.nb_cameras;
	camera = data->scene.camera;
	first_camera = *camera;
	i = 0;
	while (i < nb_cameras - 1)
	{
		camera[i] = camera[i + 1];
		i++;
	}
	camera[i] = first_camera;
	data->ui_state.to_render = 1;
	return (0);
}
