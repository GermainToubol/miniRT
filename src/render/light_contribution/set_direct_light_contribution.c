/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direct_light_contribution.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:19:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 13:45:42 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_contribution.h"
#include "t_math.h"

int	set_direct_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data)
{
	int		i;
	t_light	*light;

	i = 0;
	(void)ratio;
	(void)color;
	while (i < data->scene.nb_lights)
	{
		light = &data->scene.light[i];
		v_dot_product(intersection->norm, v_sub(light->pos, intersection->pos));
		i++;
	}
	return (0);
}
