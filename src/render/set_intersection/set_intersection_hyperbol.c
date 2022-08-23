/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_hyperbol.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:25:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 11:10:39 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "scene.h"
#include "t_math.h"

static float	get_distance(float delta, float *params)
{
	float	t1;
	float	t2;
	float	d1;
	float	d2;
	float	root;

	if (params[0] == 0)
	{
		if (params[1] == 0)
		{
			if (params[2] == 0)
				return (-1.0f);
			return (-1.0f);
		}
		return (-params[2]/params[1]);
	}
	if (delta < 0)
		return (-1.0f);
	root = sqrtf(delta);
	t1 = -0.5f * (params[1] + root) / params[0];
	t2 = -0.5f * (params[1] - root) / params[0];
	d1 = params[4] + t1 * params[5];
	d2 = params[4] + t2 * params[5];
	if (d1 * d1 <= params[3] && t1 > 0 && (t1 < t2 || t2 <= 0 || d2 * d2 > params[3]))
		return (t1);
	if (d2 * d2 <= params[3] && t2 > 0 && (t2 < t1 || t1 <= 0 || d1 * d1 > params[3]))
		return (t2);
	return (-1.0f);
}

float	set_intersection_hyperbol(t_obj *obj, t_ray *ray)
{
	t_vect	u;
	t_vect	v;
	float	delta;
	float	params[6];

	u = v_sub(ray->pos, obj->hyperbol.pos);
	u = (t_vect){v_dot_product(u, obj->hyperbol.ux),
				 v_dot_product(u, obj->hyperbol.uy),
				 v_dot_product(u, obj->hyperbol.dir),
	};
	v = (t_vect){v_dot_product(ray->dir, obj->hyperbol.ux),
				 v_dot_product(ray->dir, obj->hyperbol.uy),
				 v_dot_product(ray->dir, obj->hyperbol.dir)
	};
	params[0] = v_star_product(v, v);
	params[1] = 2 * v_star_product(u, v);
	params[2] = v_star_product(u, u) - obj->hyperbol.r * obj->hyperbol.r;
	params[3] = obj->hyperbol.h * obj->hyperbol.h * 0.25;
	params[4] = u.z;
	params[5] = v.z;
	delta = params[1] * params[1] - 4 * params[0] * params[2];
	delta = get_distance(delta, params);
	return (delta);
}
