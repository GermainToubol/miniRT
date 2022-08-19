/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:35:41 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 03:31:02 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "minirt.h"
#include "mlx.h"
#include "terminate.h"

int	init_mlx(t_data *data)
{
	t_menu	*menu;

	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	data->frame_buffer = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	menu = &data->ui_state.modifier_state.menu;
	menu->img = mlx_new_image(data->mlx, MENU_WIDTH, MENU_HEIGHT);
	menu->font.img = mlx_xpm_file_to_image(data->mlx,
			"ressources/fonts/monospace.xpm", &menu->font.w, &menu->font.h);
	menu->font.w = 10;
	menu->font.h = 12;
	if (!data->win || !data->frame_buffer || !menu->img || !menu->font.img)
		return (terminate_mlx(data), -1);
	return (0);
}
