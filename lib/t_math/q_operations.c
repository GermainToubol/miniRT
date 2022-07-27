/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:47:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/26 02:30:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

t_quat	q_add(t_quat q1, t_quat q2)
{
	t_quat	q_res;

	q_res.w = q1.w + q2.w;
	q_res.x = q1.x + q2.x;
	q_res.y = q1.y + q2.y;
	q_res.z = q1.z + q2.z;
	return (q_res);
}

t_quat	q_sub(t_quat q1, t_quat q2)
{
	t_quat	q_res;

	q_res.w = q1.w - q2.w;
	q_res.x = q1.x - q2.x;
	q_res.y = q1.y - q2.y;
	q_res.z = q1.z - q2.z;
	return (q_res);
}

t_quat	q_add_inverse(t_quat q)
{
	t_quat	q_res;

	q_res.w = -q.w;
	q_res.x = -q.x;
	q_res.y = -q.y;
	q_res.z = -q.z;
	return (q_res);
}

t_quat	q_mult(t_quat q1, t_quat q2)
{
	t_quat	q_res;

	q_res.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	q_res.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	q_res.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	q_res.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (q_res);
}

t_quat	q_inverse(t_quat q)
{
	t_quat	q_res;

	q_res.w = q.w;
	q_res.x = -q.x;
	q_res.y = -q.y;
	q_res.z = -q.z;
	return (q_res);
}
