/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:07:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 04:07:39 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "t_math.h"

t_vect	v_add(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vect	v_sub(t_vect v1, t_vect v2)
{
	return ((t_vect){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vect	v_scalar(float lambda, t_vect v)
{
	return ((t_vect){lambda * v.x, lambda * v.y, lambda * v.z});
}

float	v_norm(t_vect v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	v_dist(t_vect v1, t_vect v2)
{
	return (sqrtf((v2.x - v1.x) * (v2.x - v1.x)
			+ (v2.y - v1.y) * (v2.y - v1.y)
			+ (v2.z - v1.z) * (v2.z - v1.z)));
}
