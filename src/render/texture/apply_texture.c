/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:57:44 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/18 15:44:28 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "texture.h"

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection)
{
	const t_cboard	cboard[] = {cboard_sphere, cboard_plane, cboard_cylinder};
	const t_ftext	ftext[] = {ftext_sphere, ftext_plane};

	(void)ray;
	if (intersection->obj_seen->checkerboard
		&& intersection->obj_seen->tag <= cylinder_tag)
		(*cboard[intersection->obj_seen->tag])(color, intersection);
	else if (intersection->obj_seen->texture
		&& intersection->obj_seen->tag <= plane_tag)
		(*ftext[intersection->obj_seen->tag])(color, intersection);
	else
	{
		color->r *= intersection->obj_seen->color.r;
		color->g *= intersection->obj_seen->color.g;
		color->b *= intersection->obj_seen->color.b;
	}
	return (0);
}
