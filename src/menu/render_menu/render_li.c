/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_li.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:39:04 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 03:20:08 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_li_background(t_li *li, t_img *img, t_viewport *offset)
{
	t_viewport			view;
	static t_color_int	background_color = {0, 100, 0, 50};

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
	if (li->input_box.has_focus)
		printf("%s: \033[48;2;100;100;100m%s\033[49m\n", li->name,
			li->input_box.input);
	else
		printf("%s: %s\n", li->name, li->input_box.input);
}
