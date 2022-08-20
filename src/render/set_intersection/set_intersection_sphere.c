/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_sphere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:26:09 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:23:25 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "t_math.h"

static float	get_discriminant(t_ray *ray, t_vect *p_sphere, float r)
{
	float	delta;
	float	b;
	t_vect	obj_to_cam;

	obj_to_cam = v_sub(ray->pos, *p_sphere);
	b = v_dot_product(ray->dir, obj_to_cam);
	delta = 4 * b * b - 4 * v_dot_product(obj_to_cam, obj_to_cam) + 4 * r * r;
	return (delta);
}

static float	get_position_distance(t_obj *obj, t_ray *ray, float delta)
{
	float	t;
	float	root;
	float	b;
	t_vect	obj_to_cam;

	obj_to_cam = v_sub(ray->pos, obj->sphere.pos);
	b = 2 * v_dot_product(ray->dir, obj_to_cam);
	root = sqrtf(delta);
	if (b >= 0)
		t = -0.5f * (b - root);
	else if (-b >= root)
		t = -0.5f * (b + root);
	else
		t = -0.5f * (b - root);
	if (t < 0)
		return (-1.0f);
	return (t);
}

float	set_intersection_sphere(t_obj *obj, t_ray *ray)
{
	float	delta;

	delta = get_discriminant(ray, &obj->sphere.pos, obj->sphere.r);
	if (delta < 0)
		return (-1.0f);
	return (get_position_distance(obj, ray, delta));
}
