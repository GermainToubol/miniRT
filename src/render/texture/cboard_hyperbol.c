/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cboard_hyperbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:16:59 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 12:17:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "render.h"
#include "scene.h"
#include "t_math.h"
#include "texture.h"

static void	color_white(t_color *color, t_intersection *intersection)
{
	color->r *= intersection->obj_seen->color.r;
	color->g *= intersection->obj_seen->color.g;
	color->b *= intersection->obj_seen->color.b;
}

static void	color_black(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

int	cboard_hyperbol(t_color *color, t_intersection *intersection)
{
	t_pos	cartesian;
	t_pos	cylindrical;
	t_vect	*ux;
	t_vect	*uy;

	ux = &intersection->obj_seen->hyperbol.ux;
	uy = &intersection->obj_seen->hyperbol.uy;
	cartesian = v_sub(intersection->pos, intersection->obj_seen->hyperbol.pos);
	cartesian = (t_pos){v_dot_product(cartesian, *ux),
		v_dot_product(cartesian, *uy),
		v_dot_product(cartesian, intersection->obj_seen->hyperbol.dir)};
	cylindrical.x = sqrtf(cartesian.x * cartesian.x
			+ cartesian.y * cartesian.y);
	cylindrical.y = atan2f(cartesian.x / cylindrical.x,
			cartesian.y / cylindrical.x);
	cylindrical.z = cartesian.z;
	if (((int)(roundf(cylindrical.z + 0.0001f)
			+ roundf(cylindrical.y * 5 * INV_PI)) & 0x1) == 0)
		color_white(color, intersection);
	else
		color_black(color);
	return (0);
}
