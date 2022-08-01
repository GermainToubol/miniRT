/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:21:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 08:26:49 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

t_quat	q_get(float w, float x, float y, float z)
{
	t_quat	q;

	q.w = w;
	q.x = x;
	q.y = y;
	q.z = z;
	return (q);
}

t_quat	get_quat_from_vect(float w, t_vect v)
{
	t_quat	q;

	q.w = w;
	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
	return (q);
}

t_vect	get_vect_from_quat(t_quat q)
{
	t_vect	v;

	v.x = q.x;
	v.y = q.y;
	v.z = q.z;
	return (v);
}
