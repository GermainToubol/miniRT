/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:00:46 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 15:46:02 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "raster.h"
#include "scene.h"

int	init_light_derivates(t_scene *scene, t_light *light)
{
	int	i;

	light->mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
	if (light->mask == NULL)
		return (-1);
	i = 0;
	while (i < scene->nb_objs)
	{
		update_mask_light(scene->obj, light, i);
		i++;
	}
	return (0);
}