/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_viewports.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:28:29 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/09 22:21:38 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_state.h"

static void	set_h1_viewports(t_h1 *h1, t_viewport *offset_ext)
{
	h1->viewport = (t_viewport){offset_ext->x, offset_ext->y, H1_WIDTH,
		H1_HEIGHT};
	offset_ext->y += h1->viewport.h;
	h1->input_box.viewport = (t_viewport){0, 0, h1->viewport.w, h1->viewport.h};
}

static void	set_li_viewports(t_li *li, t_viewport *offset_ext)
{
	li->viewport = (t_viewport){offset_ext->x + LI_PAD_X, offset_ext->y,
		LI_WIDTH, LI_HEIGHT};
	offset_ext->y += li->viewport.h;
	li->input_box.viewport = (t_viewport){LI_INPUT_BOX_PAD_X, 0,
		LI_INPUT_BOX_WIDTH, LI_INPUT_BOX_HEIGHT};
}

static void	set_ul_viewports(t_ul *ul, t_viewport *offset_ext)
{
	t_viewport	offset;
	int			i;

	ul->viewport = (t_viewport){offset_ext->x, offset_ext->y, UL_WIDTH,
		UL_HEIGHT + ul->nb_li * LI_HEIGHT};
	off_ext->y += ul->viewport.h;
	offset = (t_viewport){0, UL_HEIGHT, ul->viewport.w, ul->viewport.h};
	i = 0;
	while (i < ul->nb_li)
	{
		set_li_viewports(&ul->li[i], &offset);
		i++;
	}
}

void	set_menu_viewports(t_menu *menu)
{
	t_viewport	*viewport;
	t_viewport	offset;
	int			i;

	viewport = &menu->viewport;
	*viewport = (t_viewport){MENU_X, MENU_Y, MENU_WIDTH, MENU_HEIGHT};
	offset = (t_viewport){0, 0, viewport->w, viewport->h};
	set_h1_viewports(&menu->h1, &offset);
	i = 0;
	while (i < menu->nb_ul)
	{
		set_ul_viewports(&menu->ul[i], &offset);
		i++;
	}
}
