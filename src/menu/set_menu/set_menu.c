/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:01:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 22:04:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "minirt.h"
#include "scene.h"
#include "ui_state.h"

static void	set_menu_any_obj(t_menu *menu, t_scene *scene, int i)
{
	static void	(*set_menu_obj[])(t_menu *, t_obj *) = {set_menu_sphere,
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
	set_ul_vect(&menu->ul[0], &light->pos, MENU_NAME_POS);
	set_ul_ratio(&menu->ul[1], &light->ratio, MENU_NAME_RATIO);
	set_ul_color(&menu->ul[2], &light->color, MENU_NAME_COLOR);
}

static void	set_menu_ambient_light(t_menu *menu, t_scene *scene, int i)
{
	t_ambient_light	*ambient_light;

	ambient_light = &scene->ambient_light[i];
	set_h1(&menu->h1, ambient_light->name);
	menu->nb_ul = 2;
	set_ul_ratio(&menu->ul[0], &ambient_light->ratio, MENU_NAME_RATIO);
	set_ul_color(&menu->ul[1], &ambient_light->color, MENU_NAME_COLOR);
}

static void	set_menu_camera(t_menu *menu, t_scene *scene, int i)
{
	t_camera	*camera;

	camera = &scene->camera[i];
	set_h1(&menu->h1, camera->name);
	menu->nb_ul = 4;
	set_ul_vect(&menu->ul[0], &camera->pos, MENU_NAME_POS);
	set_ul_vect(&menu->ul[1], &camera->dir, MENU_NAME_DIR);
	set_ul_fov(&menu->ul[2], &camera->fov, MENU_NAME_FOV);
	set_ul_vect(&menu->ul[3], &camera->rot_axis, MENU_NAME_ROT_AXIS);
}

void	set_menu(t_data *data, t_modifier_state *modifier_state)
{
	static void	(*set_menu_type[])(t_menu *, t_scene *, int) = {
		set_menu_any_obj, set_menu_light, set_menu_ambient_light,
		set_menu_camera};
	t_menu		*menu;
	t_elem_type	e_type;

	menu = &modifier_state->menu;
	e_type = modifier_state->elem_type;
	(set_menu_type[e_type])(
		menu,
		&data->scene,
		modifier_state->i_elem[e_type]);
	set_menu_viewports(menu);
	set_menu_focus(menu);
}
