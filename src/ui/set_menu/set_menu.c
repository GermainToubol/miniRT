/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:01:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/09 21:17:46 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"
#include "scene.h"
#include "ui_state.h"

static void	set_menu_any_obj(t_menu *menu, t_scene *scene, int i)
{
	static void	(*set_menu_obj)(t_menu *menu, t_obj *obj) = {set_menu_sphere,
		set_menu_plane, set_menu_cylinder, set_menu_triangle};
	t_obj		*obj;

	obj = &scene->obj[i];
	(set_menu_obj[obj->tag])(menu, obj);
}

static void	set_menu_light(t_menu *menu, t_scene *scene, int i)
{
	t_light	*light;

	light = &scene->light[i];
	set_h1(&menu->h1, light->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &light->pos, "Position");
	set_ul_ratio(&menu->ul[1], &light->ratio, "Ratio");
	set_ul_color(&menu->ul[2], &light->color, "Color");
}

static void	set_menu_ambient_light(t_menu *menu, t_scene *scene, int i)
{
	t_ambient_light	*ambient_light;

	ambient_light = &scene->ambient_light[i];
	set_h1(&menu->h1, ambient_light->name);
	menu->nb_ul = 2;
	set_ul_ratio(&menu->ul[0], &ambient_light->ratio, "Ratio");
	set_ul_color(&menu->ul[1], &ambient_light->color, "Color");
}

static void	set_menu_camera(t_menu *menu, t_scene *scene, int i)
{
	t_camera	*camera;

	camera = &scene->camera[i];
	set_h1(&menu->h1, camera->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &camera->pos, "Position");
	set_ul_vect(&menu->ul[1], &camera->dir, "Direction");
	set_ul_fov(&menu->ul[2], &camera->fov, "Fov");
}

void	set_menu(t_data *data, t_modifier_state *modifier_state)
{
	static void	(*set_menu_type)(t_menu *, t_scene *, int) = {set_menu_any_obj,
		set_menu_light, set_menu_ambient_light, set_menu_camera};
	t_elem_type	e_type;

	e_type = modifier_state->elem_type;
	(set_menu_type[e_type])(
		&modifier_state->menu,
		&data->scene,
		modifer_state->i_elem[e_type]);
	set_menu_viewports(&modifier_state->menu);
}
