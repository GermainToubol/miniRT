/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:18:36 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "scene.h"
#include "t_math.h"

/**
   Set the position of the intersection between an object and a ray.
*/

int	set_intersection_pos(t_pos *pos, t_obj **obj_seen, t_ray *ray, t_data *data)
{
	int							i;
	float						dist_min;
	float						tmp_dist;
	const t_intersection_func	intersect[] = {set_intersection_sphere,
		set_intersection_plane, set_intersection_cylinder,
		set_intersection_triangle, set_intersection_hyperbol};

	i = -1;
	dist_min = -1.0f;
	while (++i < data->scene.nb_objs)
	{
		if (v_dot_product(ray->dir, data->scene.camera[0].mask[i].dir)
			< data->scene.camera[0].mask[i].angle)
			continue ;
		tmp_dist = (*intersect[data->scene.obj[i].tag])(data->scene.obj
				+ i, ray);
		if (tmp_dist > 0 && (dist_min < 0 || (tmp_dist < dist_min)))
		{
			dist_min = tmp_dist;
			*obj_seen = data->scene.obj + i;
		}
	}
	if (dist_min >= 0)
		return (v_copy(pos, v_add(ray->pos, v_scalar(dist_min, ray->dir))), 0);
	return (1);
}
