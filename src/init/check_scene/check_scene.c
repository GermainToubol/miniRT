/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:39:54 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 19:00:15 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"

static int	error_elem_format_any_type(char **elem, int *nb_elem_type)
{
	static char	*rt_elem[] = {RT_AMBIENT_LIGHT, RT_CAMERA, RT_LIGHT, RT_SPHERE,
		RT_PLANE, RT_CYLINDER, RT_TRIANGLE, NULL};
	static int	(*rt_error_elem_format[])(char **) = {
		rt_error_ambient_light_format, rt_error_camera_format,
		rt_error_light_format, rt_error_sphere_format, rt_error_plane_format,
		rt_error_cylinder_format, rt_error_triangle_format};
	int			i;

	if (elem[0] == NULL)
		return (0);
	i = 0;
	while (rt_elem[i])
	{
		if (ft_strcmp(elem[0], rt_elem[i]) == 0)
		{
			nb_elem_type[i] += 1;
			if (ft_isupper(elem[0][0]) && nb_elem_type[i] > 1)
				return (rt_print_error(ERROR_MULTIPLE_UNIQUE_ELEM, elem, 0), 2);
			return ((rt_error_elem_format[i])(elem));
		}
		i++;
	}
	rt_print_error(ERROR_WRONG_ELEM_TYPE, elem, 0);
	return (1);
}

static int	check_line_format(char *line, int *nb_elem_type)
{
	char	**elem;

	elem = ft_split(line, " \n");
	if (!elem)
		return (1);
	if (error_elem_format_any_type(elem, nb_elem_type))
		return (ft_free_tab(elem), 2);
	ft_free_tab(elem);
	return (0);
}

int	check_scene(char **scene_lines)
{
	int	nb_elem_type[6];
	int	ret_value;

	ft_memset_int(nb_elem_type, 0, 6);
	while (*scene_lines)
	{
		ret_value = check_line_format(*scene_lines, nb_elem_type);
		if (ret_value != 0)
			return (ret_value);
		scene_lines++;
	}
	return (0);
}
