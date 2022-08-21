/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:33:37 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 04:37:34 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "t_math.h"

static void	set_d_bounds_sphere(t_obj *obj, t_camera *cam)
{
	float	d2_center;
	float	r;

	d2_center = v_dist2(obj->sphere.pos, cam->pos);
	r = obj->sphere.r;
	obj->d2_majorant = d2_center + r * r;
	obj->d2_minorant = f_abs(d2_center - r * r);
}

void	update_sphere(t_obj *obj, t_camera *cam)
{
	set_d_bounds_sphere(obj, cam);
}
