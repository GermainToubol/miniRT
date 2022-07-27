/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:13:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:50:40 by rgarrigo         ###   ########.fr       */
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

static void	free_rays(t_ray **ray)
{
	int	i;

	if (!ray)
		return ;
	i = 0;
	while (i < WIDTH)
	{
		free(ray[i]);
		i++;
	}
	free(ray);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free_rays(scene->ray);
	free(scene->obj);
	free(scene->light);
}

void	terminate(t_data *data)
{
	terminate_mlx(data);
	free_scene(&data->scene);
}
