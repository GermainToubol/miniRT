/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direct_light_contribution.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:19:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/31 13:30:35 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "render.h"
#include "scene.h"
#include "t_math.h"

static int	inter_on_path(t_vect *to_light, t_intersection *intersection,
				t_data *data, t_light *light)
{
	int							i;
	float						tmp_dist;
	float						dist_light;
	t_ray						ray;
	const t_intersection_func	isect[] = {set_intersection_sphere,
		set_intersection_plane, set_intersection_cylinder,
		set_intersection_triangle, set_intersection_hyperbol};

	i = -1;
	ray.dir = *to_light;
	ray.pos = v_add(intersection->pos, v_scalar(SHIFT, intersection->norm));
	v_normalize(&ray.dir);
	dist_light = v_dot_product(*to_light, *to_light);
	while (++i < data->scene.nb_objs)
	{
		if (v_dot_product(ray.dir, light->mask[i].dir) < light->mask[i].angle)
			continue ;
		tmp_dist = (*isect[data->scene.obj[i].tag])(data->scene.obj + i, &ray);
		if (tmp_dist > 0 && tmp_dist * tmp_dist < dist_light)
			return (0);
	}
	return (1);
}

static void	current_color_update(t_color *color, float ratio, t_light *light)
{
	color->r += ratio * light->color.r;
	color->g += ratio * light->color.g;
	color->b += ratio * light->color.b;
}

int	set_direct_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data)
{
	int		i;
	t_light	*light;
	t_vect	inter_light;
	float	r_color;
	float	r0;

	i = -1;
	while (++i < data->scene.nb_lights)
	{
		light = &data->scene.light[i];
		inter_light = v_sub(light->pos, intersection->pos);
		v_normalize(&inter_light);
		r_color = v_dot_product(intersection->norm, inter_light);
		inter_light = v_sub(light->pos, intersection->pos);
		if (r_color >= 0
			&& inter_on_path(&inter_light, intersection, data, light) != 0)
		{
			r0 = *ratio; // * D_SCALE / v_dot_product(inter_light, inter_light);
			set_specular_contribution(intersection, &r0, &inter_light,
				light);
			current_color_update(color, r0 * r_color * light->ratio, light);
		}
	}
	return (0);
}
