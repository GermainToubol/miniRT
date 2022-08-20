/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_hyperbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:25:29 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:19:36 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_hyperbol(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	*normal = v_sub(*pos, obj_seen->hyperbol.pos);
	normal->z *= -1;
	if (v_dot_product(ray->dir, *normal) > 0)
		v_copy(normal, v_sub(obj_seen->sphere.pos, *pos));
	v_normalize(normal);
	return (0);
}
