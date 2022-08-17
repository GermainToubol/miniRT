/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:26:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 12:30:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "light_contribution.h"
#include "minirt.h"
#include "ray.h"
#include "scene.h"
#include "texture.h"

static int	set_color_seen(t_color *color, float ratio,
	t_ray *ray, t_intersection *intersection)
{
	(void) ratio;
	(void) ray;
	if (apply_texture(color, ray, intersection) != 0)
		return (-1);
	color->r += intersection->specular.r;
	color->g += intersection->specular.g;
	color->b += intersection->specular.b;
	return (0);
}

/*
  Ratio is set to get a color of [...] at max intensity of one light
  using a (1 - exp(-I/I0)) light scaling.
*/

int	set_color(t_color *color, t_ray *ray, t_data *data)
{
	t_intersection	intersection;
	float			ratio;
	int				ret_value;

	ratio = RATIO;
	ret_value = set_intersection(&intersection, ray, data);
	if (ret_value == -1)
		return (-1);
	if (ret_value == 1)
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
		return (0);
	}
	if (set_light_contribution(color, &ratio, &intersection, data) == -1)
		return (-1);
	if (set_color_seen(color, ratio, ray, &intersection) == -1)
		return (-1);
	return (0);
}
