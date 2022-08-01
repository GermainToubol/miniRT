/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:35:41 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 19:01:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "minirt.h"
#include "mlx.h"
#include "terminate.h"

int	init_mlx(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->frame_buffer = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	if (!data->win)
		return (terminate_mlx(data), -1);
	data->frame_buffer = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->frame_buffer)
		return (terminate_mlx(data), -1);
	data->to_render = 1;
	return (0);
}
