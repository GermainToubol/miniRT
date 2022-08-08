/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:21:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/08 10:37:50 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

t_quat	q_get(float w, float x, float y, float z)
{
	return ((t_quat){w, x, y, z});
}

t_quat	get_quat_from_vect(float w, t_vect v)
{
	return ((t_quat){w, v.x, v.y, v.z});
}

t_vect	get_vect_from_quat(t_quat q)
{
	return ((t_vect){q.x, q.y, q.z});
}
