/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:10:42 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 18:59:18 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include "events.h"
#include "minirt.h"

int	manage_buttonpress_default(int buttonsym, int mouse_x, int mouse_y,
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

int	manage_buttonrelease_default(int buttonsym, int mouse_x, int mouse_y,
	t_data *data)
{
	static t_correspondence_button_buttonevent	correspondence[] = {
	{Button1, manage_buttonrelease_left_default},
	{Button2, manage_buttonrelease_middle_default},
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

int	manage_keypress_default(int keysym, t_data *data)
{
	static t_correspondence_key_keyevent	correspondence[] = {
	{XK_Escape, close_window}, {XK_Tab, switch_ui_mode},
	{XK_Control_L, set_control}, {XK_Control_R, set_control},
	{XK_P, print_frame_buffer}, {XK_p, print_frame_buffer},
	{XK_C, change_cam}, {XK_c, change_cam},
	{XK_Left, move_cam_left}, {XK_Right, move_cam_right},
	{XK_Down, move_cam_down}, {XK_Up, move_cam_up},
	{XK_Z, move_cam_forward}, {XK_z, move_cam_forward},
	{XK_X, move_cam_backward}, {XK_x, move_cam_backward},
	{XK_E, rotate_cam_roll}, {XK_e, rotate_cam_roll},
	{XK_Q, rotate_cam_reverse_roll}, {XK_q, rotate_cam_reverse_roll},
	{XK_W, rotate_cam_pitch}, {XK_w, rotate_cam_pitch},
	{XK_S, rotate_cam_reverse_pitch}, {XK_s, rotate_cam_reverse_pitch},
	{XK_A, rotate_cam_yaw}, {XK_a, rotate_cam_yaw},
	{XK_D, rotate_cam_reverse_yaw}, {XK_d, rotate_cam_reverse_yaw}, {0, NULL}};
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

int	manage_keyrelease_default(int keysym, t_data *data)
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
}
