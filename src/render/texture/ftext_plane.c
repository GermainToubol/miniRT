/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:23:18 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:29:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include "render.h"
#include "scene.h"
#include "texture.h"
#include "t_math.h"

int	ftext_plane(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_texture	*texture;
	int			pos;

	obj = intersection->obj_seen;
	texture = obj->texture;
	dx = (uint16_t)roundf(TEXTURE_SCALE * v_dot_product(obj->plane.ux,
				v_sub(intersection->pos, obj->plane.pos)));
	dy = (uint16_t)roundf(TEXTURE_SCALE * v_dot_product(obj->plane.uy,
				v_sub(intersection->pos, obj->plane.pos)));
	pos = dx % texture->width + (dy % texture->height) * texture->width;
	color->r *= texture->img[pos].r;
	color->g *= texture->img[pos].g;
	color->b *= texture->img[pos].b;
	return (0);
}

int	fbump_plane(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_bumpmap	*bumpmap;
	int			pos;

	obj = intersection->obj_seen;
	bumpmap = obj->bumpmap;
	dx = (uint16_t)roundf(TEXTURE_SCALE * v_dot_product(obj->plane.ux,
				v_sub(intersection->pos, obj->plane.pos)));
	dy = (uint16_t)roundf(TEXTURE_SCALE * v_dot_product(obj->plane.uy,
				v_sub(intersection->pos, obj->plane.pos)));
	pos = dx % bumpmap->width + (dy % bumpmap->height) * bumpmap->width;
	color->r *= bumpmap->img[pos];
	color->g *= bumpmap->img[pos];
	color->b *= bumpmap->img[pos];
	return (0);
}
