/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menu_focus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:01:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:47:13 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

static void	set_input_box_list_li(t_li *li, t_input_box **prev)
{
	li->input_box.prev = *prev;
	li->input_box.prev->next = &li->input_box;
	*prev = &li->input_box;
}

static void	set_input_box_list_ul(t_ul *ul, t_input_box **prev)
{
	int	i;

	i = 0;
	while (i < ul->nb_li)
	{
		set_input_box_list_li(&ul->li[i], prev);
		i++;
	}
}

static void	set_input_box_list_uls(t_menu *menu, t_input_box **prev)
{
	int	i;

	i = 0;
	while (i < menu->nb_ul)
	{
		set_input_box_list_ul(&menu->ul[i], prev);
		i++;
	}
}

static void	set_input_box_list(t_menu * menu)
{
	t_input_box	*prev;

	prev = &menu->h1.input_box;
	set_input_box_list_uls(menu, &prev);
	menu->h1.input_box.prev = prev;
	menu->h1.input_box.prev->next = &menu->h1.input_box;
}

void	set_menu_focus(t_menu *menu)
{
	set_input_box_list(menu);
	if (menu->input_box_focus)
		menu->input_box_focus->has_focus = 0;
	menu->input_box_focus = &menu->h1.input_box;
	menu->input_box_focus->has_focus = 1;
}
