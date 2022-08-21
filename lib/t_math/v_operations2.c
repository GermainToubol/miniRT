/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:17:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 04:08:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

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

t_vect	v_scalar_product(t_vect v1, t_vect v2)
{
	return ((t_vect){
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z});
}

t_vect	v_cross_product(t_vect v1, t_vect v2)
{
	return ((t_vect){
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x});
}
