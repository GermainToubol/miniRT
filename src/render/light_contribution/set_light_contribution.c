/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light_contribution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:17:22 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 13:46:47 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_contribution.h"

int	set_light_contribution(
		t_color *color,
		float *ratio,
		t_intersection *intersection,
		t_data *data
	)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	*ratio = 1.0f / (float)(data->scene.nb_lights + 1);
	set_ambient_light_contribution(color, ratio, intersection, data);
	set_direct_light_contribution(color, ratio, intersection, data);
	return (0);
}
