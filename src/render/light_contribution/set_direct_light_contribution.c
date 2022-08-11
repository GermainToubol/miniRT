/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direct_light_contribution.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:19:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 10:11:45 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "intersection.h"
#include "light_contribution.h"
#include "t_math.h"

static int	intersection_on_path(t_vect *to_light, t_intersection *intersection,
				t_data *data)
{
	int							i;
	float						tmp_dist;
	float						dist_light;
	t_ray						ray;
	const t_intersection_func	isect[] = {set_intersection_sphere,
		set_intersection_plane, set_intersection_cylinder,
		set_intersection_triangle};

	i = 0;
	ray.dir = *to_light;
	ray.pos = v_add(intersection->pos, v_scalar(SHIFT, intersection->norm));
	v_normalize(&ray.dir);
	dist_light = v_dot_product(*to_light, *to_light);
	while (i < data->scene.nb_objs)
	{
		tmp_dist = (*isect[data->scene.obj[i].tag])(data->scene.obj + i, &ray);
		if (tmp_dist > 0 && tmp_dist * tmp_dist < dist_light)
			return (0);
		i++;
	}
	return (1);
}

int	set_direct_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data)
{
	int		i;
	t_light	*light;
	t_vect	intersect_light;
	float	r_color;

	i = 0;
	while (i < data->scene.nb_lights)
	{
		light = &data->scene.light[i];
		intersect_light = v_sub(light->pos, intersection->pos);
		v_normalize(&intersect_light);
		r_color = v_dot_product(intersection->norm, intersect_light);
		intersect_light = v_sub(light->pos, intersection->pos);
		if (r_color >= 0
			&& intersection_on_path(&intersect_light, intersection, data) != 0)
		{
			set_specular_contribution(intersection, ratio, &intersect_light,
				light);
			color->r += *ratio * r_color * light->ratio * light->color.r;
			color->g += *ratio * r_color * light->ratio * light->color.g;
			color->b += *ratio * r_color * light->ratio * light->color.b;
		}
		i++;
	}
	return (0);
}
