/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:26:09 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 13:51:03 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "init.h"

int	rt_error_ambient_light_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_ratio,
		rt_is_color, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Ratio ambient light\n",
		"Error format: Color ambient light\n",
		"Error format: Texture id ambient light\n",
		"Error format: Bumpmap id ambient light\n",
		"Error format: Checkerboard ambient light\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 3)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_camera_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_dir,
		rt_is_fov, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position camera\n",
		"Error format: Direction camera\n",
		"Error format: FOV camera\n",
		"Error format: Texture id camera\n",
		"Error format: Bumpmap id camera\n",
		"Error format: Checkerboard camera\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 4)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_light_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_ratio,
		rt_is_color, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position light\n",
		"Error format: Ratio light\n",
		"Error format: Color light\n",
		"Error format: Texture id light\n",
		"Error format: Bumpmap id light\n",
		"Error format: Checkerboard light\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 4)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_sphere_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos,
		rt_is_diameter, rt_is_color, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position sphere\n",
		"Error format: Diameter sphere\n",
		"Error format: Color sphere\n",
		"Error format: Texture id sphere\n",
		"Error format: Bumpmap id sphere\n",
		"Error format: Checkerboard sphere\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 4)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_plane_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos,
		rt_is_dir, rt_is_color, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position plane\n",
		"Error format: Direction plane\n",
		"Error format: Color plane\n",
		"Error format: Texture id plane\n",
		"Error format: Bumpmap id plane\n",
		"Error format: Checkerboard plane\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 4)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}
