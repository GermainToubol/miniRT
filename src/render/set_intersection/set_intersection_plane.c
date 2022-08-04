/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:47:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 00:47:23 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "ray.h"
#include "scene.h"
#include "t_math.h"

float	set_intersection_plane(t_obj *obj, t_ray *ray)
{
	float	norm_scal_dir;
	float	dist;

	norm_scal_dir = v_dot_product(ray->dir, obj->plane.normal);
	if (norm_scal_dir == 0)
		return (-1.0f);
	dist = - v_dot_product(v_sub(ray->pos, obj->plane.pos), obj->plane.normal);
	dist /= norm_scal_dir;
	return (dist);
}
