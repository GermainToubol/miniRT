/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:10:42 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 03:57:28 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include "events.h"
#include "minirt.h"

int	manage_buttonpress(int buttonsym, int mouse_x, int mouse_y, t_data *data)
{
	static t_button_correspondance	button_corres[] = {
	{Button1, manage_left_press},
	{Button2, manage_middle_press},
	{Button3, manage_right_press},
	{Button4, manage_roll_up},
	{Button5, manage_roll_down},
	{0, NULL}};
	int								i;

	i = 0;
	while (button_corres[i].buttonsym)
	{
		if (buttonsym == button_corres[i].buttonsym)
			return ((button_corres[i].manage_button_event)(mouse_x, mouse_y,
				data));
		i++;
	}
	return (1);
}

int	manage_buttonrelease(int buttonsym, int mouse_x, int mouse_y, t_data *data)
{
	static t_button_correspondance	button_corres[] = {
	{Button1, manage_left_release},
	{Button2, manage_middle_release},
	{Button3, manage_right_release},
	{Button4, manage_roll_up_release},
	{Button5, manage_roll_down_release},
	{0, NULL}};
	int								i;

	i = 0;
	while (button_corres[i].buttonsym)
	{
		if (buttonsym == button_corres[i].buttonsym)
			return ((button_corres[i].manage_button_event)(mouse_x, mouse_y,
				data));
		i++;
	}
	return (1);
}

int	manage_keypress(int keysym, t_data *data)
{
	static t_key_correspondance	key_corres[] = {{XK_Escape, close_window},
	{XK_Left, move_left}, {XK_Right, move_right},
	{XK_Down, move_down}, {XK_Up, move_up},
	{XK_Z, move_forward}, {XK_z, move_forward},
	{XK_X, move_backward}, {XK_x, move_backward},
	{XK_E, rotate_roll}, {XK_e, rotate_roll},
	{XK_Q, rotate_roll_reverse}, {XK_q, rotate_roll_reverse},
	{XK_W, rotate_pitch}, {XK_w, rotate_pitch},
	{XK_S, rotate_pitch_reverse}, {XK_s, rotate_pitch_reverse},
	{XK_A, rotate_yaw}, {XK_a, rotate_yaw},
	{XK_D, rotate_yaw_reverse}, {XK_d, rotate_yaw_reverse},
	{0, NULL}};
	int							i;

	i = 0;
	while (key_corres[i].keysym)
	{
		if (keysym == key_corres[i].keysym)
			return ((key_corres[i].manage_key_event)(data));
		i++;
	}
	return (1);
}

int	manage_keyrelease(int keysym, t_data *data)
{
	(void) keysym;
	(void) data;
	return (0);
}
