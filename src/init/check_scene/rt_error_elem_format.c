/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:26:09 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:56:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "init.h"

int	rt_error_ambient_light_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_ratio,
		rt_is_color, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Ratio ambient light\n",
		"Error format: Color ambient light\n"};
	int			i;

	i = 1;
	while (rt_is_correct_type[i])
	{
		if (!elem[i])
			return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
		i++;
	}
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_camera_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_dir,
		rt_is_fov, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position camera\n",
		"Error format: Direction camera\n",
		"Error format: FOV camera\n"};
	int			i;

	i = 1;
	while (rt_is_correct_type[i])
	{
		if (!elem[i])
			return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
		i++;
	}
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_light_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_ratio,
		rt_is_color, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position light\n",
		"Error format: Ratio light\n",
		"Error format: Color light\n"};
	int			i;

	i = 1;
	while (rt_is_correct_type[i])
	{
		if (!elem[i])
			return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
		i++;
	}
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_sphere_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos,
		rt_is_diameter, rt_is_color, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position sphere\n",
		"Error format: Diameter sphere\n",
		"Error format: Color sphere\n"};
	int			i;

	i = 1;
	while (rt_is_correct_type[i])
	{
		if (!elem[i])
			return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
		i++;
	}
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_plane_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos,
		rt_is_dir, rt_is_color, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position plane\n",
		"Error format: Direction plane\n",
		"Error format: Color plane\n"};
	int			i;

	i = 1;
	while (rt_is_correct_type[i])
	{
		if (!elem[i])
			return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
		i++;
	}
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}
