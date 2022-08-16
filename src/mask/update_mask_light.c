/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mask_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:29:31 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 14:34:21 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raster.h"
#include "scene.h"

void	update_mask_light(t_obj *obj, t_light *light, int n)
{
	const t_mask_func init_mask[] = {
		set_sphere_mask,
		set_plane_mask,
		set_default_mask,
		set_default_mask
	};

	(*init_mask[obj[n].tag])(obj + n, light, light->mask + n);
}
