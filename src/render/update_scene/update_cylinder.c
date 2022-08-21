/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:35:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 04:32:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "t_math.h"

static void	set_d2_bounds_cylinder(t_obj *obj, t_camera *cam)
{
	float	d2_center;
	float	d2_max_to_center;
	float	r;
	float	h;

	d2_center = v_dist2(obj->cylinder.pos, cam->pos);
	r = obj->cylinder.r;
	h = obj->cylinder.h;
	d2_max_to_center = (r * r + h * h) / 4;
	obj->d2_majorant = d2_center + d2_max_to_center;
	obj->d2_minorant = f_abs(d2_center - d2_max_to_center);
}

void	update_cylinder(t_obj *obj, t_camera *cam)
{
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(obj->cylinder.dir, (t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(obj->cylinder.dir, (t_vect){0, 1, 0});
	uy = v_cross_product(obj->cylinder.dir, ux);
	obj->cylinder.ux = ux;
	obj->cylinder.uy = uy;
	obj->cylinder.up_face = v_add(obj->cylinder.pos,
			v_scalar(0.5f * obj->cylinder.h, obj->cylinder.dir));
	obj->cylinder.down_face = v_add(obj->cylinder.pos,
			v_scalar(-0.5f * obj->cylinder.h, obj->cylinder.dir));
	set_d2_bounds_cylinder(obj, cam);
}
