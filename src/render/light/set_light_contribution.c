/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light_contribution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:17:22 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/30 19:51:28 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "t_math.h"

int	set_light_contribution(
		t_color *color,
		float *ratio,
		t_intersection *intersection,
		t_data *data
	)
{
	intersection->specular.r = 0;
	intersection->specular.g = 0;
	intersection->specular.b = 0;
	set_ambient_light_contribution(color, ratio, intersection, data);
	set_direct_light_contribution(color, ratio, intersection, data);
	return (0);
}
