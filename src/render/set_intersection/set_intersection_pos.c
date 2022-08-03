/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 11:10:08 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "minirt.h"
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
	set_intersection_plane};

	i = 0;
	dist_min = -1.0f;
	while (i < data->scene.nb_objs)
	{
		tmp_dist = (*intersect[data->scene.obj[i].tag])(data->scene.obj + i, ray);
		if (tmp_dist >= 0 && (dist_min < 0 || (tmp_dist < dist_min)))
		{
			dist_min = tmp_dist;
			*obj_seen = data->scene.obj + i;
		}
		i++;
	}
	if (dist_min >= 0)
	{
		v_copy(pos, v_add(ray->pos, v_scalar(dist_min, ray->dir)));
		return (0);
	}
	return (1);
}
