/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:13:47 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:21:29 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_triangle(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	(void)pos;
	if (v_dot_product(ray->dir, obj_seen->triangle.normal) > 0)
		v_copy(normal, v_scalar(-1, obj_seen->triangle.normal));
	else
		v_copy(normal, obj_seen->triangle.normal);
	v_normalize(normal);
	return (0);
}
