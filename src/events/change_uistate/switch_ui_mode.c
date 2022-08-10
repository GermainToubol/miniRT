/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_ui_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:08:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/10 04:59:18 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

int	switch_ui_mode(t_data *data)
{
	t_ui_state	*ui_state;

	ui_state = &data->ui_state;
	ui_state->mode++;
	if (ui_state->mode >= NB_UI_MODES)
		ui_state->mode = mode_default;
	if (ui_state->mode == mode_default)
		mlx_put_image_to_window(data->mlx, data->win, data->frame_buffer, 0, 0);
	if (ui_state->mode == mode_modifier)
	{
		set_menu(data, &data->ui_state.modifier_state);
		render_menu(data, &data->ui_state.modifier_state.menu);
	}
	return (0);
}
