/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specular_contribution.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:09:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/09/01 00:14:41 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "t_math.h"

float	set_specular_contribution(
		t_intersection *intersection,
		float *ratio,
		t_vect *intersect_light,
		t_light *light
	)
{
	t_vect	reflexion;
	float	pw;

	v_normalize(intersect_light);
	v_normalize(&intersection->ray->dir);
	reflexion = v_sub(
			*intersect_light,
			v_scalar(
				2 * v_dot_product(*intersect_light, intersection->norm),
				intersection->norm
				)
			);
	pw = v_dot_product(reflexion, intersection->ray->dir);
	if (pw < 0)
		return (0.0f);
	pw = powf(pw, BRIGHTNESS) * light->ratio;
	pw *= RATIO_SPECULAR;
	intersection->specular.r += *ratio * pw * light->color.r;
	intersection->specular.g += *ratio * pw * light->color.g;
	intersection->specular.b += *ratio * pw * light->color.b;
	return (pw);
}
