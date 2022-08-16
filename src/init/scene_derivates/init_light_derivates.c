/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:00:46 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 12:25:49 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "ft.h"
#include "raster.h"
#include "scene.h"

void	set_sphere_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	t_dir	obj_to_light;
	float	d_sqr;
	float	r_sqr;

	obj_to_light = v_sub(light->pos, obj->sphere.pos);
	d_sqr = v_dot_product(obj_to_light, obj_to_light);
	r_sqr = obj->sphere.r * obj->sphere.r;
	if (d_sqr < r_sqr + 0.001f)
	{
		mask->dir = (t_vect){1, 0, 0};
		mask->angle = -1.0f;
		return ;
	}
	v_normalize(&obj_to_light);
	mask->dir = obj_to_light;
	mask->angle = sqrtf(1 - r_sqr / d_sqr);
}

void	set_plane_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	t_dir	obj_to_light;

	obj_to_light = v_sub(light->pos, obj->plane.pos);
	mask->angle = 0;
	if (v_dot_product(obj_to_light, obj->plane.normal) >= 0)
		mask->dir = obj->plane.normal;
	else
		mask->dir = v_scalar(-1.0f, obj->plane.normal);
}

void	set_default_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	(void)obj;
	(void)light;
	mask->dir = (t_vect){0, 0, 1};
	mask->angle = -1;
}

int	init_light_derivates(t_scene *scene, t_light *light)
{
	int	i;
	const t_mask_func init_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_default_mask,
		set_default_mask
	};

	if (light->mask == NULL)
		light->mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
	if (light->mask == NULL)
		return (-1);
	i = 0;
	while (i < scene->nb_objs)
	{
		(*init_mask[scene->obj[i].tag])(scene->obj + i, light, light->mask + i);
		i++;
	}
	return (0);
}
