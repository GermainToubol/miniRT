/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cboard_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/12 13:50:41 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "t_math.h"
#include "texture.h"

int	cboard_plane(t_color *color, t_intersection *intersection)
{
	t_vect	*ux;
	t_vect	*uy;
	t_vect	coord;

	ux = &intersection->obj_seen->plane.ux;
	uy = &intersection->obj_seen->plane.uy;
	coord = v_sub(intersection->pos, intersection->obj_seen->plane.pos);
	if (((int)(roundf(v_dot_product(coord, *ux))
			+ roundf(v_dot_product(coord, *uy))) & 0x1) == 0)
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
