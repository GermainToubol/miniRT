/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:35:03 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 15:44:22 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derivates.h"
#include "scene.h"
#include "t_math.h"

void	init_plane_derivates(t_obj *obj)
{
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(obj->plane.normal, (t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(obj->plane.normal, (t_vect){0, 1, 0});
	uy = v_cross_product(obj->plane.normal, ux);
	obj->plane.ux = ux;
	obj->plane.uy = uy;
}