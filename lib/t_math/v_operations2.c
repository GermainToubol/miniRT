/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:17:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 09:21:44 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

float	v_dot_product(t_vect v1, t_vect v2)
{
	float	res;

	res = v1.x * v2.x;
	res += v1.y * v2.y;
	res += v1.z * v2.z;
	return (res);
}

t_vect	v_scalar_product(t_vect v1, t_vect v2)
{
	t_vect	v_res;

	v_res.x = v1.x * v2.x;
	v_res.y = v1.y * v2.y;
	v_res.z = v1.z * v2.z;
	return (v_res);
}

t_vect	v_cross_product(t_vect v1, t_vect v2)
{
	t_vect	v_res;

	v_res.x = v1.y * v2.z - v1.z * v2.y;
	v_res.y = v1.z * v2.x - v1.x * v2.z;
	v_res.z = v1.x * v2.y - v1.y * v2.x;
	return (v_res);
}

float	v_star_product(t_vect v1, t_vect v2)
{
	float	res;

	res = v1.x * v2.x;
	res += v1.y * v2.y;
	res -= v1.z * v2.z;
	return (res);
}
