/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:26:09 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 11:35:45 by gtoubol          ###   ########.fr       */
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
	float	b;
	t_vect	obj_to_cam;

	if (delta < 0)
		return (-1.0f);
	obj_to_cam = v_sub(obj->sphere.pos, ray->pos);
	b = 2 * sqrtf(v_dot_product(ray->dir, obj_to_cam));
	root = sqrtf(delta);
	if (b >= 0)
		t = -0.5f * (b - root) / v_dot_product(ray->dir, ray->dir);
	else if (-b >= root)
		t = -0.5f * (b + root) / v_dot_product(ray->dir, ray->dir);
	else
		t = -0.5f * (b - root) / v_dot_product(ray->dir, ray->dir);
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