/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char_to_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:06:13 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 04:00:06 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "minirt.h"

int	add_char_to_input(int keysym, t_data *data)
{
	t_menu	*menu;
	char	*input;
	int		len_input;

	if (keysym < ' ' || keysym > '~')
		return (0);
	menu = &data->ui_state.modifier_state.menu;
	input = menu->input_box_focus->input;
	if (menu->input_box_focus->first_input)
	{
		menu->input_box_focus->first_input = 0;
		len_input = 0;
	}
	else
		len_input = ft_strlen(input);
	if (len_input + 1 == 16)
		return (0);
	input[len_input] = keysym;
	input[len_input + 1] = 0;
	render_menu(data, menu);
	return (0);
}
