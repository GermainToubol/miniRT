/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:57:44 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/18 14:58:02 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>
#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "texture.h"
#include "t_math.h"



static void	test(t_color *color, t_intersection *intersection)
{
	uint16_t	dx;
   	uint16_t	dy;
	t_obj	*obj;
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
}

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection)
{
	const t_cboard	cboard[] = {cboard_sphere, cboard_plane, cboard_cylinder};

	(void)ray;
	if (intersection->obj_seen->checkerboard
		&& intersection->obj_seen->tag <= cylinder_tag)
		(*cboard[intersection->obj_seen->tag])(color, intersection);
	else if (intersection->obj_seen->texture)
		test(color, intersection);
	else
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	return (0);
}
