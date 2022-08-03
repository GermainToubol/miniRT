/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direct_light_contribution.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:19:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 18:34:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "light_contribution.h"
#include "t_math.h"

int	set_direct_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data)
{
	int		i;
	t_light	*light;
	t_vect	intersect_to_light;
	float	r_color;

	i = 0;
	(void)ratio;
	(void)color;
	while (i < data->scene.nb_lights)
	{
		light = &data->scene.light[i];
		intersect_to_light = v_sub(light->pos, intersection->pos);
		v_normalize(&intersect_to_light);
		r_color = v_dot_product(intersection->norm, intersect_to_light);
		if (r_color < 0)
		{
			i++;
			continue;
		}
		color->r += r_color * light->color.r;
		color->g += r_color * light->color.g;
		color->b += r_color * light->color.b;
		i++;
	}
	return (0);
}
