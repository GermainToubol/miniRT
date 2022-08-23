/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cboard_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:02:34 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 14:54:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "scene.h"
#include "t_math.h"
#include "texture.h"

int	cboard_triangle(t_color *color, t_intersection *intersection)
{
	t_vect		coord;
	t_triangle	*triangle;

	triangle = &intersection->obj_seen->triangle;
	coord = v_sub(intersection->pos, triangle->edge[0]);
	if (((int)(roundf(v_dot_product(coord, triangle->ux))
			+ roundf(v_dot_product(coord, triangle->uy))) & 0x1) == 0)
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	else
	{
		color->r *= 0;
		color->g *= 0;
		color->b *= 0;
	}
	return (0);
}
