/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_set_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:28:09 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 20:02:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "scene.h"

int	rt_set_ambient_light(t_scene *scene, char **elem, int *i_elem_category)
{
	t_ambient_light	*ambient_light;

	(void) i_elem_category;
	ambient_light = &scene->ambient_light;
	ambient_light->ratio = rt_get_ratio(elem[1]);
	ambient_light->color = rt_get_color(elem[2]);
	return (0);
}

int	rt_set_camera(t_scene *scene, char **elem, int *i_elem_category)
{
	t_camera	*camera;

	camera = scene->camera + i_elem_category[2];
	i_elem_category[2] += 1;
	camera->pos = rt_get_pos(elem[1]);
	camera->dir = rt_get_dir(elem[2]);
	camera->fov = rt_get_fov(elem[3]);
	return (0);
}

int	rt_set_light(t_scene *scene, char **elem, int *i_elem_category)
{
	t_light	*light;

	light = scene->light + i_elem_category[1];
	i_elem_category[1] += 1;
	light->pos = rt_get_pos(elem[1]);
	light->ratio = rt_get_ratio(elem[2]);
	light->color = rt_get_color(elem[3]);
	return (0);
}

int	rt_set_sphere(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_sphere	*sphere;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	obj->tag = sphere_tag;
	sphere = &obj->sphere;
	sphere->pos = rt_get_pos(elem[1]);
	sphere->r = rt_get_diameter(elem[2]) / 2;
	obj->color = rt_get_color(elem[3]);
	return (0);
}

int	rt_set_plane(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj	*obj;
	t_plane	*plane;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	obj->tag = plane_tag;
	plane = &obj->plane;
	plane->pos = rt_get_pos(elem[1]);
	plane->normal = rt_get_dir(elem[2]);
	obj->color = rt_get_color(elem[3]);
	return (0);
}
