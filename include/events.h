/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 03:01:12 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "parameters.h"

typedef struct s_data	t_data;

typedef struct s_event_state
{
	int	last_buttonpress_x;
	int	last_buttonpress_y;
	int	is_translation_in_progress;
	int	is_rotation_in_progress;
}	t_event_state;

typedef struct s_button_correspondance
{
	int	buttonsym;
	int	(*manage_button_event)(int, int, t_data *);
}	t_button_correspondance;

typedef struct s_key_correspondance
{
	int	keysym;
	int	(*manage_key_event)(t_data *);
}	t_key_correspondance;

int	manage_buttonpress(int buttonsym, int mouse_x, int mouse_y, t_data *data);
int	manage_buttonrelease(int buttonsym, int mouse_x, int mouse_y, t_data *data);
int	manage_keypress(int keysym, t_data *data);
int	manage_keyrelease(int keysym, t_data *data);

//	manage_button_press
int	manage_left_press(int mouse_x, int mouse_y, t_data *data);
int	manage_middle_press(int mouse_x, int mouse_y, t_data *data);
int	manage_right_press(int mouse_x, int mouse_y, t_data *data);
int	manage_roll_up(int mouse_x, int mouse_y, t_data *data);
int	manage_roll_down(int mouse_x, int mouse_y, t_data *data);
//	manage_button_release
int	manage_left_release(int mouse_x, int mouse_y, t_data *data);
int	manage_middle_release(int mouse_x, int mouse_y, t_data *data);
int	manage_right_release(int mouse_x, int mouse_y, t_data *data);
int	manage_roll_up_release(int mouse_x, int mouse_y, t_data *data);
int	manage_roll_down_release(int mouse_x, int mouse_y, t_data *data);
//	close_window
int	close_window(t_data *data);
//	move
int	move_backward(t_data *data);
int	move_down(t_data *data);
int	move_forward(t_data *data);
int	move_left(t_data *data);
int	move_right(t_data *data);
int	move_up(t_data *data);
//	rotate
int	rotate_roll(t_data *data);
int	rotate_roll_reverse(t_data *data);
int	rotate_pitch(t_data *data);
int	rotate_pitch_reverse(t_data *data);
int	rotate_yaw(t_data *data);
int	rotate_yaw_reverse(t_data *data);

#endif
