/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:44:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/19 01:48:07 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raster.h"
#include "scene.h"
#include "t_math.h"

void	set_plane_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	t_dir	obj_to_light;

	obj_to_light = v_sub(light->pos, obj->plane.pos);
	mask->angle = 0;
	if (v_dot_product(obj_to_light, obj->plane.normal) >= 0)
		mask->dir = obj->plane.normal;
	else
		mask->dir = v_scalar(-1.0f, obj->plane.normal);
}
