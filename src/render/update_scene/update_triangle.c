/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:15:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 04:38:07 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "t_math.h"

static void	set_d2_bounds_triangle(t_obj *obj, t_camera *cam)
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
		d2[i] = v_dist2(obj->triangle.edge[i], cam->pos);
		if (d2[i] > d2[edge_d2_max])
			edge_d2_max = i;
		if (d2[i] < d2[edge_d2_min])
			edge_d2_min = i;
		l2_adj_segments[i] = v_dist2(obj->triangle.edge[(i + 1) % 3],
				obj->triangle.edge[i])
			+ v_dist2(obj->triangle.edge[(i + 2) % 3], obj->triangle.edge[i]);
		i++;
	}
	obj->d2_majorant = d2[edge_d2_max] + l2_adj_segments[edge_d2_max];
	obj->d2_minorant = f_abs(d2[edge_d2_min] - l2_adj_segments[edge_d2_min]);
}

void	update_triangle(t_obj *obj, t_camera *cam)
{
	t_triangle	*triangle;

	triangle = &obj->triangle;
	triangle->ux = v_sub(triangle->edge[1], triangle->edge[0]);
	triangle->uy = v_sub(triangle->edge[2], triangle->edge[0]);
	triangle->normal = v_cross_product(triangle->ux, triangle->uy);
	set_d2_bounds_triangle(obj, cam);
}
