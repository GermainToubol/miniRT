/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_input_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:23:36 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 21:25:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

void	render_input_box_background(t_input_box *input_box, t_img *img,
	t_viewport *offset)
{
	t_viewport			view;
	static t_color_int	background_color = {0, 0, 100, 50};

	view = input_box->viewport;
	view.x += offset->x;
	view.y += offset->y;
	put_background_color(img, &view, &background_color);
}
