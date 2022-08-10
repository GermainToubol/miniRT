/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:56:39 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/10 06:07:56 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"
#include "minirt.h"
#include "mlx.h"
#include "mlx_int.h"

static void	copy_img(t_img *dst, t_viewport *v_dst, t_img *src,
	t_viewport *v_src)
{
	char	*dst_line;
	char	*src_line;
	int		i;
	int		j;

	dst_line = dst->data + v_dst->y * dst->size_line + v_dst->x * dst->bpp / 8;
	src_line = src->data + v_src->y * src->size_line + v_src->x * src->bpp / 8;
	i = 0;
	while (i < v_src->h)
	{
		ft_memcpy(dst_line, src_line, v_src->w * src->bpp / 8);
		j = 0;
		while (j < v_src->w * dst->bpp / 8)
		{
			dst_line[j] = (char)((unsigned char) dst_line[j] / 2);
			j++;
		}
		dst_line += dst->size_line;
		src_line += src->size_line;
		i++;
	}
}

static void	render_menu_background(t_menu *menu, void *frame_buffer)
{
	t_viewport	offset;
	int			i;

	offset = (t_viewport){0, 0, menu->viewport.w, menu->viewport.h};
	copy_img(menu->img, &offset, frame_buffer, &menu->viewport);
	render_h1_background(&menu->h1, menu->img, &offset);
	i = 0;
	while (i < menu->nb_ul)
	{
		render_ul_background(&menu->ul[i], menu->img, &offset);
		i++;
	}
}

static void	render_menu_text(t_menu *menu)
{
	t_viewport	offset;
	int			i;

	offset = menu->viewport;
	render_h1_text(&menu->h1, menu->img, &offset);
	i = 0;
	while (i < menu->nb_ul)
	{
		render_ul_text(&menu->ul[i], menu->img, &offset);
		i++;
	}
}

void	render_menu(t_data *data, t_menu *menu)
{
	render_menu_background(menu, data->frame_buffer);
	render_menu_text(menu);
	mlx_put_image_to_window(data->mlx, data->win,
		menu->img, menu->viewport.x, menu->viewport.y);
}
