/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:01:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/23 11:13:13 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "scene.h"

void	set_menu_sphere(t_menu *menu, t_obj *obj)
{
	t_sphere	*sphere;

	sphere = &obj->sphere;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &sphere->pos, MENU_NAME_POS);
	set_ul_float(&menu->ul[1], &sphere->r, MENU_NAME_R);
	set_ul_color(&menu->ul[2], &obj->color, MENU_NAME_COLOR);
}

void	set_menu_plane(t_menu *menu, t_obj *obj)
{
	t_plane	*plane;

	plane = &obj->plane;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 3;
	set_ul_vect(&menu->ul[0], &plane->pos, MENU_NAME_POS);
	set_ul_vect(&menu->ul[1], &plane->normal, MENU_NAME_NORMAL);
	set_ul_color(&menu->ul[2], &obj->color, MENU_NAME_COLOR);
}

void	set_menu_cylinder(t_menu *menu, t_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = &obj->cylinder;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 5;
	set_ul_vect(&menu->ul[0], &cylinder->pos, MENU_NAME_POS);
	set_ul_vect(&menu->ul[1], &cylinder->dir, MENU_NAME_DIR);
	set_ul_float(&menu->ul[2], &cylinder->r, MENU_NAME_R);
	set_ul_float(&menu->ul[3], &cylinder->h, MENU_NAME_H);
	set_ul_color(&menu->ul[4], &obj->color, MENU_NAME_COLOR);
}

void	set_menu_triangle(t_menu *menu, t_obj *obj)
{
	t_triangle	*triangle;

	triangle = &obj->triangle;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 4;
	set_ul_vect(&menu->ul[0], &triangle->edge[0], MENU_NAME_EDGE0);
	set_ul_vect(&menu->ul[1], &triangle->edge[1], MENU_NAME_EDGE1);
	set_ul_vect(&menu->ul[2], &triangle->edge[2], MENU_NAME_EDGE2);
	set_ul_color(&menu->ul[3], &obj->color, MENU_NAME_COLOR);
}

void	set_menu_hyperbol(t_menu *menu, t_obj *obj)
{
	t_hyperbol	*hyperbol;

	hyperbol = &obj->hyperbol;
	set_h1(&menu->h1, obj->name);
	menu->nb_ul = 5;
	set_ul_vect(&menu->ul[0], &hyperbol->pos, MENU_NAME_POS);
	set_ul_vect(&menu->ul[1], &hyperbol->dir, MENU_NAME_DIR);
	set_ul_float(&menu->ul[2], &hyperbol->r, MENU_NAME_R);
	set_ul_float(&menu->ul[3], &hyperbol->h, MENU_NAME_H);
	set_ul_color(&menu->ul[4], &obj->color, MENU_NAME_COLOR);
}
