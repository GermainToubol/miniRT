/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:39:54 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/28 01:11:01 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"

static int	error_elem_format_any_type(char **elem)
{
	const char						*elem_type[] = {"A", "C", "L", "sp", "pl",
		"cy", NULL};
	const t_rt_error_elem_format	rt_error_elem_format[] = {
		rt_error_ambient_light_format, rt_error_camera_format,
		rt_error_light_format, rt_error_sphere_format, rt_error_plane_format,
		rt_error_cylinder_format};
	int								i;

	if (elem[0] == NULL)
		return (0);
	i = 0;
	while (elem_tag[i])
	{
		if (ft_strcmp(elem[0], elem_type[i]) == 0)
			return ((rt_error_elem_format[i])(elem));
		i++;
	}
	rt_print_error(ERROR_WRONG_ELEM_TYPE, elem, 0);
	return (1);
}

static int	check_line_format(char *line)
{
	char	**elem;

	elem = ft_split(elem, " \n");
	if (!elem)
		return (1);
	if (error_elem_format_any_type(elem))
		return (ft_free_tab(elem), 2);
	ft_free_tab(elem);
	return (0);
}

int	check_scene(char **scene_lines)
{
	int	ret_value;

	while (*scene_lines)
	{
		ret_value = check_line_format(*scene_lines);
		if (ret_value != 0)
			return (ret_value);
		scene_lines++;
	}
	return (0);
}
