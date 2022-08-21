/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangle_mask.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:54:42 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 17:48:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask.h"
#include "scene.h"
#include "t_math.h"

static void	set_coneview_triangle(t_mask *mask, t_triangle *tr,
	t_pos *origin)
{
	t_pos	center;
	t_pos	pos_relative_origin;
	float	d2_obj_origin;
	float	r2_sphere;

	center = v_add(tr->edge[0], tr->edge[1]);
	center = v_add(center, tr->edge[2]);
	center = v_scalar(1.0f / 3, center);
	pos_relative_origin = v_sub(center, *origin);
	d2_obj_origin = v_norm2(pos_relative_origin);
	r2_sphere = v_dist2(center, tr->edge[0]);
	r2_sphere = f_max(r2_sphere, v_dist2(center, tr->edge[1]));
	r2_sphere = f_max(r2_sphere, v_dist2(center, tr->edge[2]));
	set_coneview_sphere(mask, &pos_relative_origin, d2_obj_origin, r2_sphere);
}

static void	set_d2_bounds_triangle(t_mask *mask, t_obj *obj, t_pos *origin)
{
	float	d2[3];
	float	l2_adj_segments[3];
	int		edge_d2_max;
	int		edge_d2_min;
	int		i;

	edge_d2_max = 0;
	edge_d2_min = 0;
	i = 0;
	while (i < 3)
	{
		d2[i] = v_dist2(obj->triangle.edge[i], *origin);
		if (d2[i] > d2[edge_d2_max])
			edge_d2_max = i;
		if (d2[i] < d2[edge_d2_min])
			edge_d2_min = i;
		l2_adj_segments[i] = v_dist2(obj->triangle.edge[(i + 1) % 3],
				obj->triangle.edge[i])
			+ v_dist2(obj->triangle.edge[(i + 2) % 3], obj->triangle.edge[i]);
		i++;
	}
	mask->d2_majorant = d2[edge_d2_max] + l2_adj_segments[edge_d2_max];
	mask->d2_minorant = f_abs(d2[edge_d2_min] - l2_adj_segments[edge_d2_min]);
}

void	set_triangle_mask(t_mask *mask, t_obj *obj, t_pos *origin)
{
	set_coneview_triangle(mask, &obj->triangle, origin);
	set_d2_bounds_triangle(mask, obj, origin);
}
