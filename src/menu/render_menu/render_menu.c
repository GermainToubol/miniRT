/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:56:39 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 21:46:03 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "minirt.h"
#include "mlx.h"

static void	render_menu_background(t_menu *menu, void *frame_buffer)
{
	t_viewport	view;
	int			i;

	view = (t_viewport){0, 0, menu->viewport.w, menu->viewport.h};
	copy_img(menu->img, &view, frame_buffer, &menu->viewport);
	render_h1_background(&menu->h1, menu->img);
	i = 0;
	while (i < menu->nb_ul)
	{
		render_ul_background(&menu->ul[i], menu->img);
		i++;
	}
}

static void	render_menu_text(t_menu *menu)
{
	int	i;

	render_h1_text(&menu->h1, menu->img, &menu->font);
	i = 0;
	while (i < menu->nb_ul)
	{
		render_ul_text(&menu->ul[i], menu->img, &menu->font);
		i++;
	}
}

void	render_menu(t_data *data, t_menu *menu)
{
	render_menu_background(menu, data->frame_buffer);
	render_menu_text(menu);
	mlx_put_image_to_window(data->mlx, data->win,
		menu->img, menu->viewport.x, menu->viewport.y);
}
