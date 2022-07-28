/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_elem_format2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:45:17 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/28 01:56:03 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	rt_error_sphere_format(char **elem)
{
	const t_rt_is_type	rt_is_correct_type[] = {NULL, rt_is_pos, rt_is_diameter,
		rt_is_color, NULL};
	const char			*error_message[] = {NULL,
		"Error elem: Position sphere\n",
		"Error elem: Diameter sphere\n",
		"Error elem: Color sphere\n"};
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
