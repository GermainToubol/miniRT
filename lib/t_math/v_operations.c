/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:07:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/31 13:48:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "t_math.h"

t_vect	v_add(t_vect v1, t_vect v2)
{
	t_vect	v_res;

	v_res.x = v1.x + v2.x;
	v_res.x = v1.y + v2.y;
	v_res.x = v1.z + v2.z;
	return (v_res);
}

t_vect	v_sub(t_vect v1, t_vect v2)
{
	t_vect	v_res;

	v_res.x = v1.x - v2.x;
	v_res.x = v1.y - v2.y;
	v_res.x = v1.z - v2.z;
	return (v_res);
}

t_vect	v_inv_add(t_vect v1, t_vect v2)
{
	t_vect	v_res;

	v_res.x = v1.x + v2.x;
	v_res.x = v1.y + v2.y;
	v_res.x = v1.z + v2.z;
	return (v_res);
}

t_vect	v_scalar(double lambda, t_vect v)
{
	t_vect	v_res;

	v_res.x = lambda * v.x;
	v_res.y = lambda * v.y;
	v_res.z = lambda * v.z;
	return (v_res);
}

double	v_norm(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
