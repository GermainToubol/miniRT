/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:12:53 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:19:21 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_cylinder(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	t_vect	tmp;

	tmp = v_sub(*pos, obj_seen->cylinder.pos);
	v_copy(normal, v_sub(tmp, v_scalar(v_dot_product(tmp,
					obj_seen->cylinder.dir), obj_seen->cylinder.dir)));
	if (v_dot_product(*normal, *normal) < (obj_seen->cylinder.r
			* obj_seen->cylinder.r - 0.0001f))
		v_copy(normal, obj_seen->cylinder.dir);
	if (v_dot_product(ray->dir, *normal) > 0)
		v_copy(normal, v_scalar(-1, *normal));
	v_normalize(normal);
	return (0);
}
