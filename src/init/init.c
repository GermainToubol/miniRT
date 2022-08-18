/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:09:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 10:04:46 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"
#include "init.h"
#include "minirt.h"
#include "terminate.h"
#include "ui_state.h"

static int	check_input(int argc, char **argv)
{
	if (argc < 2)
		return (ft_putstr_fd("Too few arguments\n", 2), -1);
	if (argc > 2 && (argc == 3 && ft_strcmp(argv[1], "-v") != 0))
		return (ft_putstr_fd("Too many arguments\n", 2), -1);
	return (0);
}

static void	init_ui_state(t_ui_state *ui_state, t_scene *scene, char **argv)
{
	ui_state->mode = mode_default;
	ui_state->verbose = (ft_strcmp(argv[1], "-v") == 0);
	ui_state->to_render = 1;
	ui_state->event_state = (t_event_state){none, 0, 0, 0};
	ui_state->modifier_state = (t_modifier_state){{0},
		type_obj,
	{scene->nb_objs, scene->nb_lights, scene->nb_ambient_lights,
		scene->nb_cameras},
	{0, 0, 0, 0}};
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
	init_ui_state(&data->ui_state, &data->scene, argv);
	if (init_mlx(data) == -1)
		return (free_scene(&data->scene), 1);
	return (0);
}
