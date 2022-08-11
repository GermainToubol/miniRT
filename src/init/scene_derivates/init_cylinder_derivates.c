/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder_derivates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:35:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 18:17:09 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derivates.h"
#include "scene.h"
#include "t_math.h"

void	init_cylinder_derivates(t_obj *obj)
{
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(obj->cylinder.dir,
			(t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(obj->cylinder.dir,
				(t_vect){0, 1, 0});
	uy = v_cross_product(obj->cylinder.dir, ux);
	obj->cylinder.ux = ux;
	obj->cylinder.uy = uy;
	obj->cylinder.up_face = v_add(obj->cylinder.pos,
		v_scalar(0.5f * obj->cylinder.h, obj->cylinder.dir));
	obj->cylinder.down_face = v_add(obj->cylinder.pos,
		v_scalar(-0.5f * obj->cylinder.h, obj->cylinder.dir));
}
