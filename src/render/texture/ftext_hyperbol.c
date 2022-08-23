/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_hyperbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:12:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 14:41:33 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdint.h>
#include "render.h"
#include "scene.h"
#include "texture.h"
#include "t_math.h"

static int	coord(t_intersection *intersection, float *dx, float *dy)
{
	t_pos	cartesian;
	t_pos	cylindrical;
	t_vect	*ux;
	t_vect	*uy;

	ux = &intersection->obj_seen->cylinder.ux;
	uy = &intersection->obj_seen->cylinder.uy;
	cartesian = v_sub(intersection->pos, intersection->obj_seen->hyperbol.pos);
	cartesian = (t_pos){v_dot_product(cartesian, *ux),
		v_dot_product(cartesian, *uy),
		v_dot_product(cartesian, intersection->obj_seen->hyperbol.dir)};
	cylindrical.x = sqrtf(cartesian.x * cartesian.x
			+ cartesian.y * cartesian.y);
	cylindrical.y = atan2f(cartesian.x / cylindrical.x,
			cartesian.y / cylindrical.x);
	cylindrical.z = cartesian.z;
	*dy = 0.5f - cylindrical.z / intersection->obj_seen->cylinder.h;
	*dx = 0.5 - (cylindrical.y) * INV_PI * 0.5;
	return (0);
}

int	ftext_hyperbol(t_color *color, t_intersection *intersection)
{
	float		dx;
	float		dy;
	t_obj		*obj;
	t_texture	*texture;
	int			pos;

	obj = intersection->obj_seen;
	texture = obj->texture;
	coord(intersection, &dx, &dy);
	pos = (int32_t)(dx * (texture->width - 1))
		+ (int32_t)(dy * (texture->height - 1)) * texture->width;
	color->r *= texture->img[pos].r;
	color->g *= texture->img[pos].g;
	color->b *= texture->img[pos].b;
	return (0);
}

int	fbump_hyperbol(t_color *color, t_intersection *intersection)
{
	float		dx;
	float		dy;
	t_obj		*obj;
	t_bumpmap	*bumpmap;
	int			pos;

	obj = intersection->obj_seen;
	bumpmap = obj->bumpmap;
	coord(intersection, &dx, &dy);
	pos = (int32_t)(dx * (bumpmap->width - 1))
		+ (int32_t)(dy * (bumpmap->height - 1)) * bumpmap->width;
	color->r *= bumpmap->img[pos];
	color->g *= bumpmap->img[pos];
	color->b *= bumpmap->img[pos];
	return (0);
}
