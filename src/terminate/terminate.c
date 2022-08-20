/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:13:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/20 17:55:51 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "menu.h"
#include "minirt.h"
#include "mlx.h"
#include "terminate.h"

void	terminate_mlx(t_data *data)
{
	t_menu	*menu;

	if (!data || !data->mlx)
		return ;
	menu = &data->ui_state.modifier_state.menu;
	if (menu->font.img)
		mlx_destroy_image(data->mlx, menu->font.img);
	if (menu->img)
		mlx_destroy_image(data->mlx, menu->img);
	if (data->frame_buffer)
		mlx_destroy_image(data->mlx, data->frame_buffer);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

static void	free_textures(t_texture *texture, int nb_textures)
{
	int	i;

	i = -1;
	if (texture)
		while (++i < nb_textures)
			free(texture[i].img);
	free(texture);
}

static void	free_bumpmaps(t_bumpmap *bumpmap, int nb_bumpmaps)
{
	int	i;

	i = -1;
	if (bumpmap)
		while (++i < nb_bumpmaps)
			free(bumpmap[i].img);
	free(bumpmap);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free(scene->obj);
	free_lights(scene->light, scene->nb_lights);
	free(scene->ambient_light);
	free_camera(scene->camera, scene->nb_cameras);
	free_textures(scene->texture, scene->nb_textures);
	free_bumpmaps(scene->bumpmap, scene->nb_bumpmaps);
}

void	terminate(t_data *data)
{
	terminate_mlx(data);
	free_scene(&data->scene);
}
