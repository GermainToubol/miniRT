/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:39:19 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 21:44:45 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_control(t_data *data)
{
	data->ui_state.event_state.control_set = 1;
	return (0);
}

int	unset_control(t_data *data)
{
	data->ui_state.event_state.control_set = 0;
	return (0);
}
