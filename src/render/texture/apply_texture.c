/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:57:44 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 14:51:54 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"
#include "texture.h"

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection)
{
	const t_cboard	cboard[] = {cboard_sphere, cboard_plane, cboard_cylinder,
		cboard_triangle, cboard_hyperbol};
	const t_ftext	ftext[] = {ftext_sphere, ftext_plane, ftext_cylinder,
		ftext_triangle, ftext_hyperbol};
	const t_fbump	fbump[] = {fbump_sphere, fbump_plane, fbump_cylinder,
		fbump_triangle, fbump_hyperbol};

	(void)ray;
	if (intersection->obj_seen->checkerboard)
	{
		(*cboard[intersection->obj_seen->tag])(color, intersection);
		return (0);
	}
	if (intersection->obj_seen->texture)
		(*ftext[intersection->obj_seen->tag])(color, intersection);
	else
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	if (intersection->obj_seen->bumpmap)
		(*fbump[intersection->obj_seen->tag])(color, intersection);
	return (0);
}
