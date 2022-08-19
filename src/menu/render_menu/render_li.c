/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_li.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:39:04 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 19:49:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

void	render_li_background(t_li *li, t_img *img, t_viewport *offset)
{
	t_viewport			view;
	static t_color_int	background_color = {
		LI_BACKGROUND_R,
		LI_BACKGROUND_G,
		LI_BACKGROUND_B,
		LI_BACKGROUND_A};

	view = li->viewport;
	view.x += offset->x;
	view.y += offset->y;
	put_background_color(img, &view, &background_color);
	render_input_box_background(&li->input_box, img, &view);
}

void	render_li_text(t_li *li, t_img *img, t_font *font, t_viewport *offset)
{
	t_viewport	view;

	view = li->viewport;
	view.x += offset->x;
	view.y += offset->y;
	put_mlx_str(li->name, &view, font, img);
	render_input_box_text(&li->input_box, img, font, &view);
}
