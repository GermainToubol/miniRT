/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mask_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:29:31 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 12:00:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask.h"
#include "scene.h"

void	update_mask_light(t_mask *mask, t_light *light,
	t_obj *obj)
{
	const t_mask_func	set_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_cylinder_mask,
		set_triangle_mask,
		set_hyperbol_mask
	};

	(*set_mask[obj->tag])(mask, obj, &light->pos);
	mask->dir = v_scalar(-1.0f, mask->dir);
}

void	update_masks_light(t_light *light, t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_objs)
		update_mask_light(light->mask + i, light, scene->obj + i);
}

void	update_mask_lights(t_scene *scene, int n)
{
	int	i;

	i = -1;
	while (++i < scene->nb_lights)
		update_mask_light(scene->light[i].mask + n, scene->light + i,
			scene->obj + n);
}

void	update_masks_lights(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_lights)
		update_masks_light(scene->light + i, scene);
}
