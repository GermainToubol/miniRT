/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:30:29 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 03:24:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "mlx.h"
#include "mlx_int.h"

void	put_mlx_char(unsigned char c, t_viewport *view, t_font *font,
	void *frame_buffer)
{
	t_img	*img;
	char	*dst_line;
	char	*src_line;
	int		x;
	int		y;

	img = (t_img *) frame_buffer;
	dst_line = img->data + (view->y + font->h / 2) * img->size_line
		+ (view->x + font->w / 2) * img->bpp / 8;
	src_line = font->img->data
		+ c / 16 * font->h * font->img->size_line
		+ c % 16 * font->w * font->img->bpp / 8;
	y = 0;
	while (y++ < font->h)
	{
		x = 0;
		while (x < font->w * img->bpp / 8)
		{
			if (src_line[x + 3] == 0)
				ft_memcpy(dst_line + x, src_line + x, img->bpp / 8);
			x += img->bpp / 8;
		}
		dst_line += img->size_line;
		src_line += font->img->size_line;
	}
}

void	put_mlx_str(char *str, t_viewport *viewport, t_font *font,
	void *frame_buffer)
{
	t_viewport	viewport_char;
	int			i;

	viewport_char = *viewport;
	i = 0;
	while (str[i])
	{
		put_mlx_char(str[i], &viewport_char, font, frame_buffer);
		viewport_char.x += font->w;
		i++;
	}
}

void	put_mlx_nbr(int nbr, t_viewport *viewport, t_font *font,
	void *frame_buffer)
{
	static char	buffer[11] = {0};
	int			is_pos;
	int			i;

	is_pos = (nbr >= 0);
	i = 10;
	while (nbr != 0 && i != 10)
	{
		i--;
		if (is_pos)
			buffer[i] = '0' + nbr % 10;
		else
			buffer[i] = '0' - nbr % 10;
		nbr /= 10;
	}
	if (!is_pos)
		buffer[--i] = '-';
	put_mlx_str(buffer + i, viewport, font, frame_buffer);
}
