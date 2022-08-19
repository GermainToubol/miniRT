/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hyperbol_derivates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:00:37 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/19 11:01:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derivates.h"
#include "scene.h"
#include "t_math.h"

void	init_hyperbol_derivates(t_obj *obj)
{
	t_vect	ux;
	t_vect	uy;

	ux = v_cross_product(obj->hyperbol.dir,
			(t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(obj->hyperbol.dir,
				(t_vect){0, 1, 0});
	uy = v_cross_product(obj->hyperbol.dir, ux);
	obj->hyperbol.ux = ux;
	obj->hyperbol.uy = uy;
}
