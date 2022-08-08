/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_ui_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:08:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/08 10:12:10 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include <stdio.h>

int	switch_ui_mode(t_data *data)
{
	t_ui_state	*ui_state;

	ui_state = &data->ui_state;
	ui_state->mode++;
	if (ui_state->mode >= NB_UI_MODES)
		ui_state->mode = mode_default;
	printf("Ui_mode: %d\n", ui_state->mode);
	return (0);
}
