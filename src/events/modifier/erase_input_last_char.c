/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_input_last_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:31:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/16 23:38:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "minirt.h"

int	erase_input_last_char(t_data *data)
{
	t_menu	*menu;
	char	*input;
	int		len_input;

	menu = &data->ui_state.modifier_state.menu;
	input = menu->input_box_focus->input;
	len_input = ft_strlen(input);
	if (len_input == 0)
		return (0);
	input[len_input - 1] = 0;
	render_menu(data, menu);
	return (0);
}
