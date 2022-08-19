/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:51:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 19:48:44 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

void	render_h1_background(t_h1 *h1, t_img *img)
{
	static t_color_int	background_color = {
		H1_BACKGROUND_R,
		H1_BACKGROUND_G,
		H1_BACKGROUND_B,
		H1_BACKGROUND_A};
	static t_color_int	background_color_focus = {
		H1_FOCUS_BACKGROUND_R,
		H1_FOCUS_BACKGROUND_G,
		H1_FOCUS_BACKGROUND_B,
		H1_FOCUS_BACKGROUND_A};

	if (h1->input_box.has_focus)
		put_background_color(img, &h1->viewport, &background_color_focus);
	else
		put_background_color(img, &h1->viewport, &background_color);
}

void	render_h1_text(t_h1 *h1, t_img *img, t_font *font)
{
	put_mlx_str(h1->input_box.input, &h1->viewport, font, img);
}
