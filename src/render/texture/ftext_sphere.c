/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:34:40 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:30:22 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include "render.h"
#include "scene.h"
#include "texture.h"
#include "t_math.h"

int	ftext_sphere(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_texture	*texture;
	int			pos;

	obj = intersection->obj_seen;
	texture = obj->texture;
	dx = roundf((texture->width - 1) * (0.5f + 0.5f * INV_PI
				* atan2(-intersection->norm.x, intersection->norm.y)));
	dy = roundf((texture->height - 1)
			* (0.5f + asin(-intersection->norm.z) * INV_PI));
	pos = dx + dy * texture->width;
	color->r *= texture->img[pos].r;
	color->g *= texture->img[pos].g;
	color->b *= texture->img[pos].b;
	return (0);
}

int	fbump_sphere(t_color *color, t_intersection *intersection)
{
	int32_t		dx;
	int32_t		dy;
	t_obj		*obj;
	t_bumpmap	*bumpmap;
	int			pos;

	obj = intersection->obj_seen;
	bumpmap = obj->bumpmap;
	dx = roundf((bumpmap->width - 1) * (0.5f + 0.5f
				* INV_PI * atan2(-intersection->norm.x, intersection->norm.y)));
	dy = roundf((bumpmap->height - 1)
			* (0.5f + asin(-intersection->norm.z) * INV_PI));
	pos = dx + dy * bumpmap->width;
	color->r *= bumpmap->img[pos];
	color->g *= bumpmap->img[pos];
	color->b *= bumpmap->img[pos];
	return (0);
}
