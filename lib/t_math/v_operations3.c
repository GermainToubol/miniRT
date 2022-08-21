/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:20:12 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 16:20:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_math.h"

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
