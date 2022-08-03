/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light_contribution.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:53:24 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/02 18:16:31 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_contribution.h"

int	set_ambient_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data)
{
	(void)ratio;
	(void)intersection;
	color->r = *ratio * data->scene.ambient_light.color.r
		* data->scene.ambient_light.ratio;
	color->g = *ratio * data->scene.ambient_light.color.g
		* data->scene.ambient_light.ratio;
	color->b = *ratio * data->scene.ambient_light.color.b
		* data->scene.ambient_light.ratio;
	return (0);
}
