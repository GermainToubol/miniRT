/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:52:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:32:31 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include "events.h"
#include "init.h"
#include "minirt.h"
#include "mlx.h"
#include "render.h"
#include "terminate.h"

static void	run(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, &manage_keypress, data);
	mlx_hook(data->win, KeyRelease, KeyPressMask, &manage_keyrelease, data);
	mlx_hook(data->win, ClientMessage, 0, &close_window, data);
	mlx_loop_hook(data->mlx, &render, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret_value;

	ret_value = init(&data, argc, argv);
	if (ret_value != 0)
		return (ret_value);
	run(&data);
	terminate(&data);
	return (0);
}
