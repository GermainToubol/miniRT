/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event_modifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:10:42 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 21:42:57 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include "events.h"
#include "minirt.h"

int	manage_buttonpress_modifier(int buttonsym, int mouse_x, int mouse_y,
	t_data *data)
{
	static t_correspondence_button_buttonevent	correspondence[] = {
	{Button1, manage_buttonpress_left_default},
	{Button2, manage_buttonpress_middle_default},
	{Button3, manage_buttonpress_right_default},
	{Button4, rollmove_cam_forward},
	{Button5, rollmove_cam_backward},
	{0, NULL}};
	int											i;

	i = 0;
	while (correspondence[i].buttonsym)
	{
		if (buttonsym == correspondence[i].buttonsym)
			return ((correspondence[i].manage_buttonevent)(mouse_x, mouse_y,
				data));
		i++;
	}
	return (0);
}

int	manage_buttonrelease_modifier(int buttonsym, int mouse_x, int mouse_y,
	t_data *data)
{
	static t_correspondence_button_buttonevent	correspondence[] = {
	{Button1, manage_buttonrelease_left_default},
	{Button2, manage_buttonpress_middle_default},
	{Button3, manage_buttonrelease_right_default},
	{0, NULL}};
	int											i;

	i = 0;
	while (correspondence[i].buttonsym)
	{
		if (buttonsym == correspondence[i].buttonsym)
			return ((correspondence[i].manage_buttonevent)(mouse_x, mouse_y,
				data));
		i++;
	}
	return (0);
}

int	manage_keypress_modifier(int keysym, t_data *data)
{
	static t_correspondence_key_keyevent	correspondence[] = {
	{XK_Escape, close_window},
	{XK_Tab, switch_ui_mode},
	{XK_Control_L, set_control}, {XK_Control_R, set_control},
	{XK_Left, hand_focus_to_previous},
	{XK_Right, hand_focus_to_next},
	{0, NULL}};
	int										i;

	i = 0;
	while (correspondence[i].keysym)
	{
		if (keysym == correspondence[i].keysym)
			return ((correspondence[i].manage_keyevent)(data));
		i++;
	}
	return (0);
}

int	manage_keyrelease_modifier(int keysym, t_data *data)
{
	static t_correspondence_key_keyevent	correspondence[] = {
	{XK_Control_L, unset_control}, {XK_Control_R, unset_control},
	{0, NULL}};
	int										i;

	i = 0;
	while (correspondence[i].keysym)
	{
		if (keysym == correspondence[i].keysym)
			return ((correspondence[i].manage_keyevent)(data));
		i++;
	}
	return (0);
	return (0);
}
