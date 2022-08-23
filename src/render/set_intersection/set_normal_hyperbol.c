/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_hyperbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:25:29 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 14:57:17 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_hyperbol(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	float		x;
	float		y;
	float		z;
	t_hyperbol	*hyperbol;

	hyperbol = &obj_seen->hyperbol;
	*normal = v_sub(*pos, obj_seen->hyperbol.pos);
	x = v_dot_product(*normal, hyperbol->ux);
	y = v_dot_product(*normal, hyperbol->uy);
	z = v_dot_product(*normal, hyperbol->dir);
	*normal = v_sub(v_add(v_scalar(x, hyperbol->ux),
				v_scalar(y, hyperbol->uy)),
			v_scalar(z, hyperbol->dir));
	if (v_dot_product(ray->dir, *normal) > 0)
		v_copy(normal, v_sub(obj_seen->sphere.pos, *pos));
	v_normalize(normal);
	return (0);
}
