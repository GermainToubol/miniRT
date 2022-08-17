/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_masks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:06:50 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 16:13:29 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"
#include "scene.h"

int	alloc_masks(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nb_cameras)
	{
		scene->camera[i].mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
		if (scene->camera[i].mask == NULL)
			return (-1);
	}
	i = -1;
	while (++i < scene->nb_lights)
	{
		scene->light[i].mask = ft_calloc(scene->nb_objs, sizeof(t_mask));
		if (scene->light[i].mask == NULL)
			return (-1);
	}
	return (0);
}
