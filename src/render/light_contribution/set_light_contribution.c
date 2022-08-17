/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light_contribution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:17:22 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 13:42:57 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_contribution.h"
#include "t_math.h"

int	set_light_contribution(
		t_color *color,
		float *ratio,
		t_intersection *intersection,
		t_data *data
	)
{
	t_vect	tmp;

	color->r = 0;
	color->g = 0;
	color->b = 0;
	intersection->specular.r = 0;
	intersection->specular.g = 0;
	intersection->specular.b = 0;
	tmp = v_sub(intersection->pos, intersection->ray->pos);
	set_ambient_light_contribution(color, ratio, intersection, data);
	set_direct_light_contribution(color, ratio, intersection, data);
	return (0);
}
