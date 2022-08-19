/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:51:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 03:44:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

void	render_h1_background(t_h1 *h1, t_img *img)
{
	static t_color_int	background_color = {30, 30, 30, 100};
	static t_color_int	background_color_focus = {50, 50, 50, 100};

	if (h1->input_box.has_focus)
		put_background_color(img, &h1->viewport, &background_color_focus);
	else
		put_background_color(img, &h1->viewport, &background_color);
}

void	render_h1_text(t_h1 *h1, t_img *img, t_font *font)
{
	put_mlx_str(h1->input_box.input, &h1->viewport, font, img);
}
