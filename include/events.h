/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 21:40:39 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"
# include "parameters.h"

typedef struct s_correspondence_uimode_buttonevent
{
	t_ui_mode	mode;
	int			(*manage_buttonevent)(int, int, int, t_data *);
}	t_correspondence_uimode_buttonevent;

typedef struct s_correspondence_uimode_keyevent
{
	t_ui_mode	mode;
	int			(*manage_keyevent)(int, t_data *);
}	t_correspondence_uimode_keyevent;

typedef struct s_correspondence_button_buttonevent
{
	int	buttonsym;
	int	(*manage_buttonevent)(int, int, t_data *);
}	t_correspondence_button_buttonevent;

typedef struct s_correspondence_key_keyevent
{
	int	keysym;
	int	(*manage_keyevent)(t_data *);
}	t_correspondence_key_keyevent;

//	CHANGE_UI_STATE
int		close_window(t_data *data);
int		set_control(t_data *data);
int		switch_ui_mode(t_data *data);
int		unset_control(t_data *data);

//	MANAGE_EVENT
//	manage_buttonpress_default
int		manage_buttonpress_left_default(int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonpress_middle_default(int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonpress_right_default(int mouse_x, int mouse_y,
			t_data *data);
//	manage_buttonrelease_default
int		manage_buttonrelease_left_default(int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonrelease_middle_default(int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonrelease_right_default(int mouse_x, int mouse_y,
			t_data *data);
//	manage_event
int		manage_buttonpress(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonrelease(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_keypress(int keysym, t_data *data);
int		manage_keyrelease(int keysym, t_data *data);
//	manage_event_default
int		manage_buttonpress_default(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonrelease_default(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_keypress_default(int keysym, t_data *data);
int		manage_keyrelease_default(int keysym, t_data *data);
//	manage_event_modifier
int		manage_buttonpress_modifier(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_buttonrelease_modifier(int buttonsym, int mouse_x, int mouse_y,
			t_data *data);
int		manage_keypress_modifier(int keysym, t_data *data);
int		manage_keyrelease_modifier(int keysym, t_data *data);

//	MODIFIER
//	hand_focus
int		hand_focus_to_next(t_data *data);
int		hand_focus_to_previous(t_data *data);

//	TRANSFORM_CAMERA
//	buttonmove_cam
void	buttonmove_cam(int mouse_x, int mouse_y, t_camera *camera,
			t_event_state *event_state);
void	set_buttonmove_cam(int mouse_x, int mouse_y,
			t_event_state *event_state);
//	buttonrotate_cam
void	buttonrotate_cam(int mouse_x, int mouse_y, t_camera *camera,
			t_event_state *event_state);
void	set_buttonrotate_cam(int mouse_x, int mouse_y,
			t_event_state *event_state);
//	move_cam
int		move_cam_left(t_data *data);
int		move_cam_up(t_data *data);
int		move_cam_right(t_data *data);
int		move_cam_down(t_data *data);
int		move_cam_forward(t_data *data);
int		move_cam_backward(t_data *data);
//	rollmove_cam
int		rollmove_cam_forward(int mouse_x, int mouse_y, t_data *data);
int		rollmove_cam_backward(int mouse_x, int mouse_y, t_data *data);
//	rotate_cam
int		rotate_cam_roll(t_data *data);
int		rotate_cam_reverse_roll(t_data *data);
int		rotate_cam_pitch(t_data *data);
int		rotate_cam_reverse_pitch(t_data *data);
int		rotate_cam_yaw(t_data *data);
int		rotate_cam_reverse_yaw(t_data *data);

//	TRANSFORM_LIGHT

//	TRANSFORM_OBJ

#endif
