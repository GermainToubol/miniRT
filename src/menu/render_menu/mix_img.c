/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:10:23 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 20:33:23 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx_int.h"

void	copy_img(t_img *dst, t_viewport *v_dst, t_img *src,
	t_viewport *v_src)
{
	char	*dst_line;
	char	*src_line;
	int		y;

	dst_line = dst->data + v_dst->y * dst->size_line + v_dst->x * dst->bpp / 8;
	src_line = src->data + v_src->y * src->size_line + v_src->x * src->bpp / 8;
	y = 0;
	while (y < v_src->h)
	{
		ft_memcpy(dst_line, src_line, v_src->w * src->bpp / 8);
		dst_line += dst->size_line;
		src_line += src->size_line;
		y++;
	}
}

void	put_background_color(t_img *dst, t_viewport *view, t_color_int *color)
{
	unsigned char	*line;
	float			ratio;
	int				x;
	int				y;

	ratio = ((float) color->a) / 255;
	line = (unsigned char *) dst->data + view->y * dst->size_line
		+ view->x * dst->bpp / 8;
	y = 0;
	while (y < view->h)
	{
		x = 0;
		while (x < view->w * dst->bpp / 8)
		{
			line[x + 2] = line[x + 2] * ratio + color->r * (1 - ratio);
			line[x + 1] = line[x + 1] * ratio + color->g * (1 - ratio);
			line[x] = line[x] * ratio + color->b * (1 - ratio);
			x += dst->bpp / 8;
		}
		line += dst->size_line;
		y++;
	}
}
