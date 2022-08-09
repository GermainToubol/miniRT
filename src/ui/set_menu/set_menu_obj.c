/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:01:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/09 21:27:07 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"
#include "scene.h"
#include "ui_state.h"

void	set_menu_sphere(t_menu *menu, t_obj *obj, int i)
{
	t_sphere	*sphere;

	sphere = &obj->sphere;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &sphere->pos, "Position");
	set_ul_float(&menu->ul[1], &sphere->r, "Radius");
	set_ul_color(&menu->ul[2], &obj->color, "Color");
}

void	set_menu_plane(t_menu *menu, t_obj *obj, int i)
{
	t_plane	*plane;

	plane = &obj->plane;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &plane->pos, "Position");
	set_ul_vect(&menu->ul[1], &plane->dir, "Normal");
	set_ul_color(&menu->ul[2], &obj->color, "Color");
}

void	set_menu_cylinder(t_menu *menu, t_obj *obj, int i)
{
	t_cylinder	*cylinder;

	cylinder = &obj->cylinder;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 5;
	set_ul_vect(&menu->ul[0], &cylinder->pos, "Position");
	set_ul_vect(&menu->ul[1], &cylinder->dir, "Direction");
	set_ul_float(&menu->ul[2], &cylinder->r, "Radius");
	set_ul_float(&menu->ul[3], &cylinder->h, "Height");
	set_ul_color(&menu->ul[4], &obj->color, "Color");
}

void	set_menu_triangle(t_menu *menu, t_obj *obj, int i)
{
	t_triangle	*triangle;

	triangle = &obj->triangle;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 4;
	set_ul_vect(&menu->ul[0], &triangle->edge[0], "Edge 1");
	set_ul_vect(&menu->ul[1], &triangle->edge[1], "Edge 2");
	set_ul_vect(&menu->ul[2], &triangle->edge[2], "Edge 3");
	set_ul_color(&menu->ul[3], &obj->color, "Color");
}
