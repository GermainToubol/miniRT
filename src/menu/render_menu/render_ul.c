/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 03:00:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 21:46:33 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_ul_background(t_ul *ul, t_img *img)
{
	t_viewport			offset;
	static t_color_int	background_color = {100, 0, 0, 50};
	int					i;

	offset = (t_viewport){ul->viewport.x, ul->viewport.y, UL_WIDTH, UL_HEIGHT};
	put_background_color(img, &offset, &background_color);
	i = 0;
	while (i < ul->nb_li)
	{
		render_li_background(&ul->li[i], img, &offset);
		i++;
	}
}

void	render_ul_text(t_ul *ul, t_img *img, t_font *font)
{
	int	i;

	printf("%s\n", ul->name);
	i = 0;
	while (i < ul->nb_li)
	{
		render_li_text(&ul->li[i], img, font);
		i++;
	}
}
