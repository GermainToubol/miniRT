/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_math.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:53:36 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/02 18:21:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MATH_H
# define T_MATH_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quat;

//Vectors

t_vect	v_get(double x, double y, double z);

t_vect	v_add(t_vect v1, t_vect v2);
t_vect	v_sub(t_vect v1, t_vect v2);
t_vect	v_inv_add(t_vect v1, t_vect v2);
t_vect	v_scalar(double lambda, t_vect v);
double	v_norm(t_vect v);
t_vect	v_cross_product(t_vect v1, t_vect v2);
double	v_dot_product(t_vect v1, t_vect v2);
t_vect	v_scalar_product(t_vect v1, t_vect v2);

void	v_normalize(t_vect *v);
void	v_translate(t_vect *pos, t_vect move);
void	v_rotate(t_vect *dir, t_vect dir_rot, double theta);

// Quaternions

t_quat	q_get(double w, double x, double y, double z);
t_quat	get_quat_from_vect(double w, t_vect v);
t_vect	get_vect_from_quat(t_quat v);

t_quat	q_add(t_quat q1, t_quat q2);
t_quat	q_sub(t_quat q1, t_quat q2);
t_quat	q_add_inverse(t_quat q);
t_quat	q_mult(t_quat q1, t_quat q2);
t_quat	q_inverse(t_quat q);

#endif
