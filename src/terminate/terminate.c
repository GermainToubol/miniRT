/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:13:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 20:36:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"
#include "mlx.h"
#include "parameters.h"

void	terminate_mlx(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->frame_buffer)
		mlx_destroy_image(data->mlx, data->frame_buffer);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free(scene->obj);
	free(scene->light);
	free(scene->camera);
}

void	terminate(t_data *data)
{
	terminate_mlx(data);
	free_scene(&data->scene);
}
