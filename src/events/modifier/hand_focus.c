/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_focus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:18:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/08 13:47:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ui_state.h"

#include <stdio.h>

static int	hand_focus_to_next_type(t_modifier_state *modifier_state)
{
	modifier_state->elem_type++;
	if (modifier_state->elem_type == NB_ELEM_TYPES)
		modifier_state->elem_type = type_obj;
	return (0);
}

int	hand_focus_to_next(t_data *data)
{
	t_modifier_state	*modifier_state;
	t_elem_type			e_type;

	modifier_state = &data->ui_state.modifier_state;
	if (data->ui_state.event_state.control_set)
		return (hand_focus_to_next_type(modifier_state));
	e_type = modifier_state->elem_type;
	modifier_state->i_elem[e_type]++;
	if (modifier_state->i_elem[e_type] == modifier_state->nb_elems[e_type])
		modifier_state->i_elem[e_type] = 0;
	if (modifier_state->elem_type == type_obj)
		printf("%s\n", data->scene.obj[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_light)
		printf("%s\n", data->scene.light[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_ambient_light)
		printf("%s\n",
			data->scene.ambient_light[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_camera)
		printf("%s\n", data->scene.camera[modifier_state->i_elem[e_type]].name);
	return (0);
}

static int	hand_focus_to_previous_type(t_modifier_state *modifier_state)
{
	modifier_state->elem_type--;
	if ((int) modifier_state->elem_type == -1)
		modifier_state->elem_type = type_camera;
	return (0);
}

int	hand_focus_to_previous(t_data *data)
{
	t_modifier_state	*modifier_state;
	t_elem_type			e_type;

	modifier_state = &data->ui_state.modifier_state;
	if (data->ui_state.event_state.control_set)
		return (hand_focus_to_previous_type(modifier_state));
	e_type = modifier_state->elem_type;
	modifier_state->i_elem[e_type]--;
	if (modifier_state->i_elem[e_type] < 0)
		modifier_state->i_elem[e_type] = modifier_state->nb_elems[e_type] - 1;
	if (modifier_state->elem_type == type_obj)
		printf("%s\n", data->scene.obj[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_light)
		printf("%s\n", data->scene.light[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_ambient_light)
		printf("%s\n",
			data->scene.ambient_light[modifier_state->i_elem[e_type]].name);
	if (modifier_state->elem_type == type_camera)
		printf("%s\n", data->scene.camera[modifier_state->i_elem[e_type]].name);
	return (0);
}
