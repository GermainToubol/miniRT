/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:51:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:48:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_h1_background(t_h1 *h1, t_img *img, t_viewport *offset)
{
	char	*img_line;
	int		i;

	img_line = img->data
		+ (offset->y + h1->viewport.y) * img->size_line
		+ (offset->x + h1->viewport.x) * img->bpp / 8;
	i = 0;
	while (i < h1->viewport.h)
	{
		ft_memset(img_line, 100, h1->viewport.w * img->bpp / 8);
		img_line += img->size_line;
		i++;
	}
}

void	render_h1_text(t_h1 *h1, t_img *img, t_viewport *offset)
{
	(void) img;
	(void) offset;
	printf("\n");
	if (h1->input_box.has_focus)
		printf("\033[48;2;100;100;100m%s\033[49m\n", h1->input_box.input);
	else
		printf("%s\n", h1->input_box.input);
}
