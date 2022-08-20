/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:15:32 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/20 17:34:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "t_math.h"

void	update_triangle(t_obj *obj)
{
	t_triangle	*triangle;

	triangle = &obj->triangle;
	triangle->ux = v_sub(triangle->edge[1], triangle->edge[0]);
	triangle->uy = v_sub(triangle->edge[2], triangle->edge[0]);
	triangle->normal = v_cross_product(triangle->ux, triangle->uy);
}
