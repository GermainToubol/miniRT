/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:51:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/10 04:57:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

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
	(void) h1;
	(void) img;
	(void) offset;
}
