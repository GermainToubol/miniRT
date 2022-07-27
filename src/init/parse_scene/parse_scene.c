/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:41:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:50:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "scene.h"

int	parse_scene(t_scene *scene, char **scene_lines)
{
	(void) scene_lines;
	scene->ray = NULL;
	scene->obj = NULL;
	scene->light = NULL;
	return (0);
}
