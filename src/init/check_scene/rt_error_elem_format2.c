/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:45:17 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:56:08 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "init.h"

int	rt_error_cylinder_format(char **elem)
{
	static int	(*rt_is_correct_type[])(char *) = {NULL, rt_is_pos, rt_is_dir,
		rt_is_diameter, rt_is_height, rt_is_color, NULL};
	static char	*error_message[] = {NULL,
		"Error format: Position cylinder\n",
		"Error format: Direction cylinder\n",
		"Error format: Diameter cylinder\n",
		"Error format: Height cylinder\n",
		"Error format: Color cylinder\n"};
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
