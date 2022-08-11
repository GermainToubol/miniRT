/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_cylinder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:03:36 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 10:45:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "intersection.h"
#include "ray.h"
#include "scene.h"
#include "t_math.h"

static float	get_distance(float delta, float *params)
{
	float	t;
	float	b;
	float	c;
	float	root;

	if (delta < 0)
		return (-1.0f);
	b = 2 * params[1] * params[2];
	root = sqrtf(delta);
	if (b >= 0)
		t = -0.5f * (b - root) / (params[2] * params[2]);
	if (-b >= root)
	{
		t = -0.5f * (b + root) / (params[2] * params[2]);
		c = params[3] + t * params[4];
	}
	if (b < 0 && (-b < root || (c * c > params[6] * params[6] / 4)))
		t = -0.5f * (b - root) / (params[2] * params[2]);
	c = params[3] + t * params[4];
	if (c * c > params[6] * params[6] / 4)
		return (-2.0f);
	if (t < 0)
		return (-1.0f);
	return (t);
}

float	distance_discs(t_obj *obj, t_ray *ray, float radius)
{
	float	norm_scal_dir;
	float	dist;
	t_vect	tmp;

	norm_scal_dir = v_dot_product(ray->dir, obj->plane.normal);
	if (norm_scal_dir == 0)
		return (-1.0f);
	dist = -v_dot_product(v_sub(ray->pos, obj->plane.pos), obj->plane.normal);
	dist /= norm_scal_dir;
	tmp = v_add(ray->pos, v_scalar(dist, ray->dir));
	tmp = v_sub(tmp, obj->plane.pos);
	if (v_dot_product(tmp, tmp) > radius * radius)
		return (-1.0f);
	return (dist);
}

static float	distance_edges(float d, t_obj *obj, t_ray *ray)
{
	float	d1;
	float	d2;
	t_obj	tmp;

	if (d == -1.0f)
		return (-1.0f);
	tmp.plane.normal = obj->cylinder.dir;
	v_normalize(&tmp.plane.normal);
	tmp.plane.pos = v_add(obj->cylinder.pos, v_scalar(obj->cylinder.h / 2,
				tmp.plane.normal));
	d1 = distance_discs(&tmp, ray, obj->cylinder.r);
	tmp.plane.pos = v_add(obj->cylinder.pos, v_scalar(-obj->cylinder.h / 2,
				tmp.plane.normal));
	d2 = distance_discs(&tmp, ray, obj->cylinder.r);
	if (d1 > 0 && (d1 < d2 || d2 <= 0) && (d1 < d || d <= 0))
		return (d1);
	else if (d2 > 0 && (d2 < d1 || d1 <= 0) && (d2 < d || d <= 0))
		return (d2);
	return (d);
}

float	set_intersection_cylinder(t_obj *obj, t_ray *ray)
{
	float	params[7];
	t_vect	base[3];
	float	delta;

	base[0] = v_cross_product(obj->cylinder.dir, ray->dir);
	base[2] = obj->cylinder.dir;
	base[1] = v_cross_product(base[2], base[0]);
	v_normalize(&base[0]);
	v_normalize(&base[1]);
	v_normalize(&base[2]);
	params[0] = v_dot_product(v_sub(ray->pos, obj->cylinder.pos), base[0]);
	params[1] = v_dot_product(v_sub(ray->pos, obj->cylinder.pos), base[1]);
	params[2] = v_dot_product(ray->dir, base[1]);
	params[3] = v_dot_product(v_sub(ray->pos, obj->cylinder.pos), base[2]);
	params[4] = v_dot_product(ray->dir, base[2]);
	params[5] = obj->cylinder.r;
	params[6] = obj->cylinder.h;
	delta = 4 * params[2] * params[2]
		* (params[5] * params[5] - params[0] * params[0]);
	delta = get_distance(delta, params);
	delta = distance_edges(delta, obj, ray);
	return (delta);
}
