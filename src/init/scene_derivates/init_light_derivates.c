/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_derivates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:00:46 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 10:41:34 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "raster.h"
#include "scene.h"

int	init_light_derivates(t_scene *scene, t_light *light)
{
	light->mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
	if (light->mask == NULL)
		return (-1);
	return (0);
}
