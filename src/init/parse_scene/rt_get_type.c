/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:50:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/31 14:38:55 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"
#include "t_math.h"

#include <stdio.h>

static void	rt_skip_to_next_number(char **str)
{
	while (**str && **str != ',')
		*str += 1;
	if (**str)
		*str += 1;
}

static t_vect	rt_get_vect(char *str)
{
	t_vect	v;

	v.x = ft_atof(str);
	rt_skip_to_next_number(&str);
	v.y = ft_atof(str);
	rt_skip_to_next_number(&str);
	v.z = ft_atof(str);
	return (v);
}

t_pos	rt_get_pos(char *str)
{
	return ((t_pos) rt_get_vect(str));
}

t_dir	rt_get_dir(char *str)
{
	t_dir	dir;

	dir = rt_get_vect(str);
	if ((dir.x < -1.0f || dir.x > 1.0f)
		|| (dir.y < -1.0f || dir.y > 1.0f)
		|| (dir.z < -1.0f || dir.z > 1.0f)
		|| (dir.x == 0 && dir.y == 0 && dir.z == 0))
		return ((t_pos){0.0f, 0.0f, 0.0f});
	v_normalize(&dir);
	return (dir);
}

t_color	rt_get_color(char *str)
{
	t_color	color;

	color.r = ft_atof(str) / 255;
	rt_skip_to_next_number(&str);
	color.g = ft_atof(str) / 255;
	rt_skip_to_next_number(&str);
	color.b = ft_atof(str) / 255;
	return (color);
}
