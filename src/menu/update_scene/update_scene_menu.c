/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:26:04 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/20 17:37:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "minirt.h"
#include "render.h"

static int	update_scene_input_box(t_input_box *input_box)
{
	static int	(*update_input_type[])(char *, void *) = {
		update_input_int,
		update_input_float,
		update_input_ratio,
		update_input_fov,
		update_input_str};

	return ((update_input_type[input_box->type])(
		input_box->input,
		input_box->ptr));
}

static int	update_scene_ul(t_ul *ul)
{
	int	i;

	i = 0;
	while (i < ul->nb_li)
	{
		update_scene_input_box(&ul->li[i].input_box);
		i++;
	}
	return (0);
}

int	update_scene_menu(t_data *data)
{
	t_menu	*menu;
	int		i;

	menu = &data->ui_state.modifier_state.menu;
	update_scene_input_box(&menu->h1.input_box);
	i = 0;
	while (i < menu->nb_ul)
	{
		update_scene_ul(&menu->ul[i]);
		i++;
	}
	data->ui_state.to_render = 1;
	render(data);
	set_menu(data, &data->ui_state.modifier_state);
	render_menu(data, menu);
	return (0);
}
