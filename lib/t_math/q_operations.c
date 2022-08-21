/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:47:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 03:52:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

t_quat	q_add(t_quat q1, t_quat q2)
{
	return ((t_quat){
		q1.w + q2.w,
		q1.x + q2.x,
		q1.y + q2.y,
		q1.z + q2.z});
}

t_quat	q_sub(t_quat q1, t_quat q2)
{
	return ((t_quat){
		q1.w - q2.w,
		q1.x - q2.x,
		q1.y - q2.y,
		q1.z - q2.z});
}

t_quat	q_add_inverse(t_quat q)
{
	return ((t_quat){
		-q.w,
		-q.x,
		-q.y,
		-q.z});
}

t_quat	q_mult(t_quat q1, t_quat q2)
{
	return ((t_quat){
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w});
}

t_quat	q_inverse(t_quat q)
{
	return ((t_quat){
		q.w,
		-q.x,
		-q.y,
		-q.z});
}
