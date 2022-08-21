/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hyperbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:00:37 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 04:12:47 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "t_math.h"

void	update_hyperbol(t_obj *obj, t_camera *cam)
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
	(void) cam;
	obj->d2_minorant = -1;
	obj->d2_majorant = -1;
}
