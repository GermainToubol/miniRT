/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cboard_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:21 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/12 13:50:22 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "light_contribution.h"
#include "scene.h"
#include "texture.h"

int	cboard_sphere(t_color *color, t_intersection *intersection)
{
	t_pos	tmp;
	float	theta;
	float	phi;

	tmp.x = intersection->pos.x - intersection->obj_seen->sphere.pos.x;
	tmp.y = intersection->pos.y - intersection->obj_seen->sphere.pos.y;
	tmp.z = intersection->pos.z - intersection->obj_seen->sphere.pos.z;
	theta = acosf(tmp.z / intersection->obj_seen->sphere.r);
	phi = atan2f(tmp.x, tmp.y);
	if (((int)(roundf(theta * INV_PI * SPHERE_PART)
			+ roundf(phi * INV_PI * SPHERE_PART)) & 0x1) == 0)
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
