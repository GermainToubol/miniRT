/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cboard_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 10:09:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "t_math.h"
#include "texture.h"

int	cboard_plane(t_color *color, t_intersection *intersection)
{
	t_vect	ux;
	t_vect	uy;
	t_vect	coord;

	ux = v_cross_product(intersection->obj_seen->plane.normal,
			(t_vect){1, 0, 0});
	if (v_dot_product(ux, ux) == 0)
		ux = v_cross_product(intersection->obj_seen->plane.normal,
				(t_vect){0, 1, 0});
	uy = v_cross_product(intersection->obj_seen->plane.normal, ux);
	coord = v_sub(intersection->pos, intersection->obj_seen->plane.pos);
	if ((int)(roundf(v_dot_product(coord, ux))
		+ roundf(v_dot_product(coord, uy))) % 2 == 0)
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	else
	{
		color->r *= 0.1 * intersection->obj_seen->color.r;
		color->g *= 0.1 * intersection->obj_seen->color.g;
		color->b *= 0.1 * intersection->obj_seen->color.b;
	}
	return (0);
}
