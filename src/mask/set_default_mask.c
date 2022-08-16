/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:45:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 15:45:59 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"
#include "scene.h"
#include "t_math.h"

void	set_default_mask(t_obj *obj, t_light *light, t_mask *mask)
{
	(void)obj;
	(void)light;
	mask->dir = (t_vect){0, 0, 1};
	mask->angle = -1;
}
