/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:51:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 21:45:54 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_h1_background(t_h1 *h1, t_img *img)
{
	static t_color_int	background_color = {200, 200, 200, 100};

	put_background_color(img, &h1->viewport, &background_color);
}

void	render_h1_text(t_h1 *h1, t_img *img, t_font *font)
{
	put_mlx_str(h1->input_box.input, &h1->viewport, font, img);
	printf("\n");
	if (h1->input_box.has_focus)
		printf("\033[48;2;100;100;100m%s\033[49m\n", h1->input_box.input);
	else
		printf("%s\n", h1->input_box.input);
}
