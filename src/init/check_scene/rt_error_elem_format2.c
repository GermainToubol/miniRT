/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:45:17 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 10:35:32 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "init.h"

int	rt_error_cylinder_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_dir,
		rt_is_diameter, rt_is_height, rt_is_color, rt_is_texture_id,
		rt_is_bumpmap_id, rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position cylinder\n",
		"Error format: Direction cylinder\n",
		"Error format: Diameter cylinder\n",
		"Error format: Height cylinder\n",
		"Error format: Color cylinder\n",
		"Error format: Texture id cylinder\n",
		"Error format: Bumpmap id cylinder\n",
		"Error format: Checkerboard cylinder\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 6)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_triangle_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_pos,
		rt_is_pos, rt_is_color, rt_is_texture_id, rt_is_bumpmap_id,
		rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position triangle edge\n",
		"Error format: Position triangle edge\n",
		"Error format: Position triangle edge\n",
		"Error format: Color cylinder\n",
		"Error format: Texture id triangle\n",
		"Error format: Bumpmap id triangle\n",
		"Error format: Checkerboard triangle\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 5)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_hyperbol_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_dir,
		rt_is_diameter, rt_is_height, rt_is_color, rt_is_texture_id,
		rt_is_bumpmap_id, rt_is_checkerboard, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position hyperbol\n",
		"Error format: Direction hyperbol\n",
		"Error format: Diameter hyperbol\n",
		"Error format: Height hyperbol\n",
		"Error format: Color hyperbol\n",
		"Error format: Texture id hyperbol\n",
		"Error format: Bumpmap id hyperbol\n",
		"Error format: Checkerboard hyperbol\n"};
	int			i;

	i = 0;
	while (++i && elem[i] && rt_is_correct_type[i])
		if (!(rt_is_correct_type[i])(elem[i]))
			return (rt_print_error(error_message[i], elem, i));
	if (i < 6)
		return (rt_print_error(ERROR_TOO_FEW_PARAMS, elem, -1));
	if (elem[i])
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_texture_format(char **elem)
{
	int	i;

	i = 1;
	while (elem[i])
		i++;
	if (i > 2)
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}

int	rt_error_bumpmap_format(char **elem)
{
	int	i;

	i = 1;
	while (elem[i])
		i++;
	if (i > 2)
		return (rt_print_error(ERROR_TOO_MANY_PARAMS, elem, -1));
	return (0);
}
