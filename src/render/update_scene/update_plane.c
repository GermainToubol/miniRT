/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:35:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 04:37:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "t_math.h"

static void	set_d2_bounds_plane(t_obj *obj, t_camera *cam)
{
	obj->d2_majorant = -1;
	obj->d2_minorant = v_dist2(obj->plane.pos, cam->pos);
}

void	update_plane(t_obj *obj, t_camera *cam)
{
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(obj->plane.normal, (t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(obj->plane.normal, (t_vect){0, 1, 0});
	uy = v_cross_product(obj->plane.normal, ux);
	obj->plane.ux = ux;
	obj->plane.uy = uy;
	set_d2_bounds_plane(obj, cam);
}
