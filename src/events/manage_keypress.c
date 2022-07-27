/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:35:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:14:38 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "events.h"
#include "minirt.h"

int	manage_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		return (close_window(data));
	return (0);
}
