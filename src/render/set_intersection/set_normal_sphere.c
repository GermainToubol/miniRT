/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:36:58 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/01 19:55:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "ray.h"
#include "scene.h"
#include "t_math.h"

int	set_normal_sphere(t_ray *ray, t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	(void)ray;
	v_copy(normal, v_sub(*pos, obj_seen->sphere.pos));
	v_normalize(normal);
	return (0);
}
