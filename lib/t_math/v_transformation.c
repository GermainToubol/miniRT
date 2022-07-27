/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_transformation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:18:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/01 02:13:13 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "t_math.h"

void	v_normalize(t_vect *v)
{
	double	norm_v;

	norm_v = v_norm(*v);
	v->x /= norm_v;
	v->y /= norm_v;
	v->z /= norm_v;
}

void	v_translate(t_vect *pos, t_vect move)
{
	pos->x += move.x;
	pos->y += move.y;
	pos->z += move.z;
}

void	v_rotate(t_vect *dir, t_vect dir_rot, double theta)
{
	t_quat	q_dir;
	t_quat	q_rot;

	q_dir = get_quat_from_vect(0, *dir);
	v_normalize(&dir_rot);
	v_scalar(cos(theta / 2), dir_rot);
	q_rot = get_quat_from_vect(sin(theta / 2), dir_rot);
	q_dir = q_mult(q_dir, q_inverse(q_rot));
	q_dir = q_mult(q_rot, q_dir);
	*dir = get_vect_from_quat(q_dir);
}
