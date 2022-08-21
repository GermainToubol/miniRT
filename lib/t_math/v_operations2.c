/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:17:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 19:53:58 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "t_math.h"

float	v_norm2(t_vect v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	v_dist2(t_vect v1, t_vect v2)
{
	return ((v2.x - v1.x) * (v2.x - v1.x)
		+ (v2.y - v1.y) * (v2.y - v1.y)
		+ (v2.z - v1.z) * (v2.z - v1.z));
}

float	v_dot_product(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float	v_star_product(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y - v1.z * v2.z);
}

float	v_angle(t_vect v1, t_vect v2)
{
	float	angle;

	angle = v_dot_product(v1, v2);
	angle /= v_norm(v1);
	angle /= v_norm(v2);
	angle = acosf(angle);
	return (angle);
}
