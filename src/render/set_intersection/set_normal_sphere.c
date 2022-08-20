/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:36:58 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:21:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_sphere(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	v_copy(normal, v_sub(*pos, obj_seen->sphere.pos));
	if (v_dot_product(ray->dir, *normal) > 0)
		v_copy(normal, v_sub(obj_seen->sphere.pos, *pos));
	v_normalize(normal);
	return (0);
}
