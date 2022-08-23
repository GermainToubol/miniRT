/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hyperbol_mask.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:58:08 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 11:58:33 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mask.h"
#include "scene.h"
#include "t_math.h"

void	set_hyperbol_mask(t_mask *mask, t_obj *obj, t_pos *origin)
{
	t_pos	pos_relative_origin;
	float	d2_obj_origin;
	float	r2_sphere;
	float	r;
	float	h;

	pos_relative_origin = v_sub(obj->sphere.pos, *origin);
	d2_obj_origin = v_norm2(pos_relative_origin);
	r = obj->hyperbol.r;
	h = obj->hyperbol.h;
	r2_sphere = r * r + h * h;
	set_coneview_sphere(mask, &pos_relative_origin, d2_obj_origin, r2_sphere);
	set_d2_bounds_sphere(mask, d2_obj_origin, r2_sphere);
}
