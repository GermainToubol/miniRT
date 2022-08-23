/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:54:24 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 14:55:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdint.h>
#include "render.h"
#include "scene.h"
#include "texture.h"
#include "t_math.h"

static int	coord(t_intersection *intersection, int32_t *dx, int32_t *dy)
{
	*dx = (int)roundf(TEXTURE_SCALE * v_dot_product(intersection->pos,
				intersection->obj_seen->triangle.ux));
	*dy = (int)roundf(TEXTURE_SCALE * v_dot_product(intersection->pos,
				intersection->obj_seen->triangle.uy));
	return (0);
}

int	ftext_triangle(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_texture	*texture;
	int			pos;

	obj = intersection->obj_seen;
	texture = obj->texture;
	coord(intersection, &dx, &dy);
	pos = dx % texture->width + (dy % texture->height) * texture->width;
	color->r *= texture->img[pos].r;
	color->g *= texture->img[pos].g;
	color->b *= texture->img[pos].b;
	return (0);
}

int	fbump_triangle(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_bumpmap	*bumpmap;
	int			pos;

	obj = intersection->obj_seen;
	bumpmap = obj->bumpmap;
	coord(intersection, &dx, &dy);
	pos = dx % bumpmap->width + (dy % bumpmap->height) * bumpmap->width;
	color->r *= bumpmap->img[pos];
	color->g *= bumpmap->img[pos];
	color->b *= bumpmap->img[pos];
	return (0);
}
