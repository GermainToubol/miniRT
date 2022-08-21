/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:56:11 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 18:56:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask.h"
#include "scene.h"

int	update_light(t_light *light, t_scene *scene)
{
	update_masks_light(light, scene);
	return (0);
}
