/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ul_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:46:39 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:50:46 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "scene.h"
#include "t_math.h"

void	set_ul_color(t_ul *ul, t_color *color, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 3;
	set_li(&ul->li[0], type_ratio, &color->r, "r");
	set_li(&ul->li[1], type_ratio, &color->g, "g");
	set_li(&ul->li[2], type_ratio, &color->b, "b");
}

void	set_ul_float(t_ul *ul, float *f, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li(&ul->li[0], type_float, f, "f");
}

void	set_ul_fov(t_ul *ul, float *fov, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li(&ul->li[0], type_fov, fov, "f");
}

void	set_ul_ratio(t_ul *ul, float *ratio, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li(&ul->li[0], type_ratio, ratio, "f");
}

void	set_ul_vect(t_ul *ul, t_vect *v, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 3;
	set_li(&ul->li[0], type_float, &v->x, "x");
	set_li(&ul->li[1], type_float, &v->y, "y");
	set_li(&ul->li[2], type_float, &v->z, "z");
}
