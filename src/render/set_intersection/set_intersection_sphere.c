/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:26:09 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 18:00:47 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "intersection.h"
#include "t_math.h"

static float	get_discriminant(t_ray *ray, t_pos *p_sphere, float r)
{
	float	delta;
	t_vect	obj_to_cam;

	obj_to_cam = v_sub(ray->pos, *p_sphere);
	delta = 4 * v_dot_product(ray->dir, obj_to_cam)
		* v_dot_product(ray->dir, obj_to_cam)
		- 4 * (v_dot_product(obj_to_cam, obj_to_cam) - r * r)
		* (v_dot_product(ray->dir, ray->dir));
	return (delta);
}

static float	get_position_distance(t_obj *obj, t_ray *ray, float delta)
{
	float	t;
	float	root;
	float	a;
	float	b;
	t_vect	obj_to_cam;

	if (delta < 0)
		return (-1.0f);
	obj_to_cam = v_sub(ray->pos, obj->sphere.pos);
	b = 2 * v_dot_product(ray->dir, obj_to_cam);
	a = 1 / v_dot_product(ray->dir, ray->dir);
	root = sqrtf(delta);
	if (b >= 0)
		t = -0.5f * (b - root) * a;
	else if (-b >= root)
		t = -0.5f * (b + root) * a;
	else
		t = -0.5f * (b - root) * a;
	if (t < 0)
		return (-1.0f);
	return (t);
}

float	set_intersection_sphere(t_obj *obj, t_ray *ray)
{
	float	delta;

	delta = get_discriminant(ray, &obj->sphere.pos, obj->sphere.r);
	return (get_position_distance(obj, ray, delta));
}
