/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder_mask.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:51 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:56:58 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mask.h"
#include "scene.h"
#include "t_math.h"

void	set_cylinder_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	t_dir	obj_to_light;
	float	d_sqr;
	float	r_sqr;

	obj_to_light = v_sub(light->pos, obj->sphere.pos);
	d_sqr = v_dot_product(obj_to_light, obj_to_light);
	r_sqr = obj->cylinder.r * obj->cylinder.r
		+ 0.25f * obj->cylinder.h * obj->cylinder.h;
	if (d_sqr < r_sqr + 0.001f)
	{
		mask->dir = (t_vect){1, 0, 0};
		mask->angle = -1.0f;
		return ;
	}
	v_normalize(&obj_to_light);
	mask->dir = obj_to_light;
	mask->angle = sqrtf(1 - r_sqr / d_sqr);
}
