/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:26:09 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/28 01:55:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	rt_error_ambient_light_format(char **elem)
{
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_ratio, rt_is_color,
		NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Ratio ambient light\n",
		"Error elem: Color ambient light\n"};
	int					i;

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
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_pos, rt_is_dir,
		rt_is_fov, NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Position camera\n",
		"Error elem: Direction camera\n",
		"Error elem: FOV camera\n"};
	int					i;

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

int	rt_error_cylinder_format(char **elem)
{
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_pos, rt_is_dir,
		rt_is_diameter, rt_is_height, rt_is_color, NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Position cylinder\n",
		"Error elem: Direction cylinder\n",
		"Error elem: Diameter cylinder\n",
		"Error elem: Height cylinder\n",
		"Error elem: Color cylinder\n"};
	int					i;

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
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_pos, rt_is_ratio,
		rt_is_color, NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Position light\n",
		"Error elem: Ratio light\n",
		"Error elem: Color light\n"};
	int					i;

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
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_pos,
		rt_is_dir, rt_is_color, NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Position plane\n",
		"Error elem: Direction plane\n",
		"Error elem: Color plane\n"};
	int					i;

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
