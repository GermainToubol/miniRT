/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_input_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:23:36 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/20 14:59:12 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

void	render_input_box_background(t_input_box *input_box, t_img *img,
	t_viewport *offset)
{
	static t_color_int	background_color = {
		INPUT_BOX_BACKGROUND_R,
		INPUT_BOX_BACKGROUND_G,
		INPUT_BOX_BACKGROUND_B,
		INPUT_BOX_BACKGROUND_A};
	static t_color_int	background_color_focus = {
		INPUT_BOX_FOCUS_BACKGROUND_R,
		INPUT_BOX_FOCUS_BACKGROUND_G,
		INPUT_BOX_FOCUS_BACKGROUND_B,
		INPUT_BOX_FOCUS_BACKGROUND_A};
	t_viewport			view;

	view = input_box->viewport;
	view.x += offset->x;
	view.y += offset->y;
	if (input_box->has_focus)
		put_background_color(img, &view, &background_color_focus);
	else
		put_background_color(img, &view, &background_color);
}

void	render_input_box_text(t_input_box *input_box, t_img *img, t_font *font,
	t_viewport *offset)
{
	t_viewport			view;

	view = input_box->viewport;
	view.x += offset->x;
	view.y += offset->y;
	put_mlx_str(input_box->input, &view, font, img);
}
