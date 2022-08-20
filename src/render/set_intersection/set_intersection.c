/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:15:07 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:15:03 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	set_intersection(t_intersection *intersection, t_ray *ray, t_data *data)
{
	if (set_intersection_pos(
			&intersection->pos,
			&intersection->obj_seen,
			ray,
			data) != 0)
		return (1);
	if (set_intersection_normal(ray, &intersection->pos, &intersection->norm,
			intersection->obj_seen))
		return (1);
	intersection->ray = ray;
	return (0);
}
