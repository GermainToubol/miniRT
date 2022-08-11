/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_focus_input_box.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:46:57 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:24:34 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "menu.h"

int	hand_focus_to_next_input_box(t_data *data)
{
	t_menu	*menu;

	menu = &data->ui_state.modifier_state.menu;
	menu->input_box_focus->has_focus = 0;
	menu->input_box_focus = menu->input_box_focus->next;
	menu->input_box_focus->has_focus = 1;
	render_menu(data, menu);
	return (0);
}

int	hand_focus_to_previous_input_box(t_data *data)
{
	t_menu	*menu;

	menu = &data->ui_state.modifier_state.menu;
	menu->input_box_focus->has_focus = 0;
	menu->input_box_focus = menu->input_box_focus->prev;
	menu->input_box_focus->has_focus = 1;
	render_menu(data, menu);
	return (0);
}
