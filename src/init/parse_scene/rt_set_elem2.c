/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_set_elem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:57:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 19:26:36 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"
#include "scene.h"

int	rt_set_cylinder(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_cylinder	*cylinder;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	ft_strlcpy(obj->name, "Cylinder XXX", 16);
	obj->tag = cylinder_tag;
	cylinder = &obj->cylinder;
	cylinder->pos = rt_get_pos(elem[1]);
	cylinder->dir = rt_get_dir(elem[2]);
	cylinder->r = rt_get_diameter(elem[3]) / 2;
	cylinder->h = rt_get_height(elem[4]);
	obj->color = rt_get_color(elem[5]);
	return (0);
}

int	rt_set_triangle(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_triangle	*triangle;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	ft_strlcpy(obj->name, "Triangle XXX", 16);
	obj->tag = triangle_tag;
	triangle = &obj->triangle;
	triangle->edge[0] = rt_get_pos(elem[1]);
	triangle->edge[1] = rt_get_pos(elem[2]);
	triangle->edge[2] = rt_get_pos(elem[3]);
	obj->color = rt_get_color(elem[4]);
	return (0);
}
