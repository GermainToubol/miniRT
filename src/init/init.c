/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:09:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:44:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"
#include "minirt.h"
#include "terminate.h"

static int	check_input(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		return (ft_putstr_fd("Too few arguments\n", 2), -1);
	if (argc > 2)
		return (ft_putstr_fd("Too many arguments\n", 2), -1);
	return (0);
}

static void	init_ui_state(t_ui_state *ui_state)
{
	t_event_state	*event_state;

	ui_state->mode = mode_default;
	ui_state->to_render = 1;
	event_state = &ui_state->event_state;
	event_state->last_buttonpress_x = 0;
	event_state->last_buttonpress_y = 0;
	event_state->action_in_progress = none;
}

int	init(t_data *data, int argc, char **argv)
{
	int	ret_value;

	ret_value = check_input(argc, argv);
	if (ret_value != 0)
		return (ret_value);
	ret_value = init_scene(&data->scene, argc, argv);
	if (ret_value != 0)
		return (ret_value);
	init_ui_state(&data->ui_state);
	if (init_mlx(data) == -1)
		return (free_scene(&data->scene), 1);
	return (0);
}
