/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_focus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:18:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/09 19:18:51 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"
#include "ui_state.h"

void	render_menu(t_data *data, t_modifier_state *modifier_state)
{
	(void) data;
	(void) modifier_state;
}

void	set_menu(t_data *data, t_modifier_state *modifier_state)
{
	(void) data;
	(void) modifier_state;
}

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
	set_menu(data, modifier_state);
	render_menu(data, modifier_state);
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
	set_menu(data, modifier_state);
	render_menu(data, modifier_state);
	return (0);
}
