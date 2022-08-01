/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersection_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:28:38 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/01 19:54:03 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "minirt.h"

int	set_intersection_normal(t_pos *pos, t_dir *normal, t_obj *obj_seen)
{
	const t_normal_func	get_normal[] = {set_normal_sphere};

	return ((*get_normal[obj_seen->tag])(pos, normal, obj_seen));
}
