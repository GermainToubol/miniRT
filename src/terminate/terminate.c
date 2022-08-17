/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:13:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 12:17:32 by rgarrigo         ###   ########.fr       */
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
	if (data->ui_state.modifier_state.menu.img)
		mlx_destroy_image(data->mlx, data->ui_state.modifier_state.menu.img);
	if (data->frame_buffer)
		mlx_destroy_image(data->mlx, data->frame_buffer);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

static void	free_textures(t_texture *texture, int nb_textures)
{
	(void) nb_textures;
	free(texture);
}

static void	free_bumpmaps(t_bumpmap *bumpmap, int nb_bumpmaps)
{
	(void) nb_bumpmaps;
	free(bumpmap);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free(scene->obj);
	free(scene->light);
	free(scene->ambient_light);
	free(scene->camera);
	free_textures(scene->texture, scene->nb_textures);
	free_bumpmaps(scene->bumpmap, scene->nb_bumpmaps);
}

void	terminate(t_data *data)
{
	terminate_mlx(data);
	free_scene(&data->scene);
}
