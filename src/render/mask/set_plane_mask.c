/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:44:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 17:59:53 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "t_math.h"

static void	set_coneview_plane(t_mask *mask, t_dir *normal,
	t_pos *pos_relative_origin)
{
	if (v_dot_product(*pos_relative_origin, *normal) >= 0)
		mask->dir = *normal;
	else
		mask->dir = v_scalar(-1.0f, *normal);
	mask->angle = 0;
}

static void	set_d2_bounds_plane(t_mask *mask, float d2_obj_origin)
{
	mask->d2_majorant = -1;
	mask->d2_minorant = d2_obj_origin;
}

void	set_plane_mask(t_mask *mask, t_obj *obj, t_pos *origin)
{
	t_pos	pos_relative_origin;

	pos_relative_origin = v_sub(obj->plane.pos, *origin);
	set_coneview_plane(mask, &obj->plane.normal, &pos_relative_origin);
	set_d2_bounds_plane(mask, v_norm2(pos_relative_origin));
}
