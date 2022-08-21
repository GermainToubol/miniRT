/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere_mask.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:43:30 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 17:48:25 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "t_math.h"

void	set_coneview_sphere(t_mask *mask, t_pos *pos_relative_origin,
	float d2_obj_origin, float r2_sphere)
{
	if (d2_obj_origin < r2_sphere + 0.001f)
	{
		mask->dir = (t_vect){1, 0, 0};
		mask->angle = -1.0f;
		return ;
	}
	mask->dir = *pos_relative_origin;
	v_normalize(&mask->dir);
	mask->angle = sqrtf(1 - r2_sphere / d2_obj_origin);
}

void	set_d2_bounds_sphere(t_mask *mask, float d2_obj_origin, float r2_sphere)
{
	mask->d2_majorant = d2_obj_origin + r2_sphere;
	mask->d2_minorant = f_abs(d2_obj_origin - r2_sphere);
}

void	set_sphere_mask(t_mask *mask, t_obj *obj, t_pos *origin)
{
	t_pos	pos_relative_origin;
	float	d2_obj_origin;
	float	r2_sphere;

	pos_relative_origin = v_sub(obj->sphere.pos, *origin);
	d2_obj_origin = v_norm2(pos_relative_origin);
	r2_sphere = obj->sphere.r * obj->sphere.r;
	set_coneview_sphere(mask, &pos_relative_origin, d2_obj_origin, r2_sphere);
	set_d2_bounds_sphere(mask, d2_obj_origin, r2_sphere);
}
