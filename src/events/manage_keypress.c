/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:10:21 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include "events.h"
#include "minirt.h"

int	manage_keypress(int keysym, t_data *data)
{
	const t_keypress_correspondance	key_corres[] = {{XK_Escape, close_window},
	{XK_Left, move_left}, {XK_A, move_left}, {XK_a, move_left},
	{XK_Up, move_up}, {XK_W, move_up}, {XK_w, move_up},
	{XK_Right, move_right}, {XK_D, move_right}, {XK_d, move_right},
	{XK_Down, move_down}, {XK_S, move_down}, {XK_s, move_down},
	{0, NULL}};
	int								i;

	i = 0;
	while (key_corres[i].keysym)
	{
		if (keysym == key_corres[i].keysym)
			return ((key_corres[i].manage_keypress)(data));
		i++;
	}
	return (1);
}
