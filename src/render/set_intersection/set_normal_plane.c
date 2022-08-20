/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:12:17 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:19:50 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_plane(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	(void)pos;
	if (v_dot_product(ray->dir, obj_seen->plane.normal) > 0)
	{
		v_copy(normal, v_scalar(-1, obj_seen->plane.normal));
		return (0);
	}
	v_copy(normal, obj_seen->plane.normal);
	return (0);
}
