/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mask_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:29:31 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 13:55:23 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raster.h"
#include "scene.h"

void	update_single_mask_single_light(t_obj *obj, t_light *light, int n)
{
	const t_mask_func	init_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_cylinder_mask,
		set_default_mask
	};

	(*init_mask[obj[n].tag])(obj + n, light, light->mask + n);
}

void	update_all_masks_single_light(t_scene *scene, t_light *light)
{
	int	i;

	i = -1;
	while (++i < scene->nb_objs)
		update_single_mask_single_light(scene->obj, light, i);
}

void	update_single_mask_all_lights(t_scene *scene, int n)
{
	int	i;

	i = -1;
	while (++i < scene->nb_lights)
		update_single_mask_single_light(scene->obj, scene->light + i, n);
}

void	update_all_masks_all_lights(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_lights)
		update_all_masks_single_light(scene, scene->light + i);
}
