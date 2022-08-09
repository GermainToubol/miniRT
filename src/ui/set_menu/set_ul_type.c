/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ul_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:46:39 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/09 20:12:18 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "modifier.h"
#include "scene.h"
#include "t_math.h"
#include "ui_state.h"

void	set_ul_vect(t_ul *ul, t_vect *v, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 3;
	set_li_float(&ul->li[0], &v->x, "x");
	set_li_float(&ul->li[1], &v->y, "y");
	set_li_float(&ul->li[2], &v->z, "z");
}

void	set_ul_color(t_ul *ul, t_color *color, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 3;
	set_li_ratio(&ul->li[0], &color->x, "r");
	set_li_ratio(&ul->li[1], &color->y, "g");
	set_li_ratio(&ul->li[2], &color->z, "b");
}

void	set_ul_float(t_ul *ul, float *f, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li_float(&ul->li[0], f, "");
}

void	set_ul_ratio(t_ul *ul, float *ratio, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li_ratio(&ul->li[0], ratio, "");
}

void	set_ul_fov(t_ul *ul, float *fov, char *name)
{
	ft_strlcpy(ul->name, name, 16);
	ul->nb_li = 1;
	set_li_fov(&ul->li[0], fov, "");
}
