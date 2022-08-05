/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_ui_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:08:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:34:26 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	switch_ui_mode(t_data *data)
{
	t_ui_state	*ui_state;

	ui_state = &data->ui_state;
	ui_state->mode++;
	ui_state->mode /= NB_UI_MODES;
	return (0);
}
