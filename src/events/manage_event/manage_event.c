/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:12:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:48:33 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "events.h"
#include "minirt.h"

int	manage_buttonpress(int buttonsym, int mouse_x, int mouse_y, t_data *data)
{
	static t_correspondence_uimode_buttonevent	correspondence[] = {
	{mode_default, manage_buttonpress_default},
	{mode_modifier, manage_buttonpress_modifier},
	{0, NULL}};
	t_ui_mode									mode;
	int											i;

	mode = data->ui_state.mode;
	i = 0;
	while (correspondence[i].mode)
	{
		if (mode == correspondence[i].mode)
			return ((correspondence[i].manage_buttonevent)(buttonsym, mouse_x,
				mouse_y, data));
		i++;
	}
	return (1);
}

int	manage_buttonrelease(int buttonsym, int mouse_x, int mouse_y, t_data *data)
{
	static t_correspondence_uimode_buttonevent	correspondence[] = {
	{mode_default, manage_buttonrelease_default},
	{mode_modifier, manage_buttonrelease_modifier},
	{0, NULL}};
	t_ui_mode									mode;
	int											i;

	mode = data->ui_state.mode;
	i = 0;
	while (correspondence[i].mode)
	{
		if (mode == correspondence[i].mode)
			return ((correspondence[i].manage_buttonevent)(buttonsym, mouse_x,
				mouse_y, data));
		i++;
	}
	return (1);
}

int	manage_keypress(int keysym, t_data *data)
{
	static t_correspondence_uimode_keyevent	correspondence[] = {
	{mode_default, manage_keypress_default},
	{mode_modifier, manage_keypress_modifier},
	{0, NULL}};
	t_ui_mode								mode;
	int										i;

	mode = data->ui_state.mode;
	i = 0;
	while (correspondence[i].mode)
	{
		if (mode == correspondence[i].mode)
			return ((correspondence[i].manage_keyevent)(keysym, data));
		i++;
	}
	return (1);
}

int	manage_keyrelease(int keysym, t_data *data)
{
	static t_correspondence_uimode_keyevent	correspondence[] = {
	{mode_default, manage_keyrelease_default},
	{mode_modifier, manage_keyrelease_modifier},
	{0, NULL}};
	t_ui_mode								mode;
	int										i;

	mode = data->ui_state.mode;
	i = 0;
	while (correspondence[i].mode)
	{
		if (mode == correspondence[i].mode)
			return ((correspondence[i].manage_keyevent)(keysym, data));
		i++;
	}
	return (1);
}
