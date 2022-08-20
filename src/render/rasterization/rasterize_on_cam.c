/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize_on_cam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:01:15 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/20 17:07:44 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterization.h"

static int	rasterize_obj_on_cam(t_obj *obj, t_camera *cam)
{
	t_line	line;

	if (set_first_line(&line, obj, cam) == -1)
		return (0);
	while (!is_line_empty(&line))
	{
		update_line(&line, obj, cam);
		if (set_next_line(&line, obj, cam) == -1)
			return (0);
	}
	return (0);
}

int	rasterize_on_cam(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->nb_objs)
	{
		rasterize_obj_on_cam(&scene->obj[i], scene->camera);
		i++;
	}
	return (0);
}
