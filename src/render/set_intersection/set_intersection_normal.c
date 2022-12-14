/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:28:38 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:15:24 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "scene.h"

int	set_intersection_normal(t_ray *ray, t_pos *pos, t_dir *normal,
		t_obj *obj_seen)
{
	const t_normal_func	get_normal[] = {
		set_normal_sphere,
		set_normal_plane,
		set_normal_cylinder,
		set_normal_triangle,
		set_normal_hyperbol
	};

	return ((*get_normal[obj_seen->tag])(ray, pos, normal, obj_seen));
}
