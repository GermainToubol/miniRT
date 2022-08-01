/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:15:07 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/01 19:43:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "intersection.h"

int	set_intersection(t_intersection *intersection, t_ray *ray, t_data *data)
{
	if(set_intersection_pos(
			&intersection->pos,
			&intersection->obj_seen,
			ray,
			data) != 0)
		return (1);
	return (0);
}
