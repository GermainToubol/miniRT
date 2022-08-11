/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_li.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:39:04 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:44:34 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_li_background(t_li *li, t_img *img, t_viewport *offset)
{
	(void) li;
	(void) img;
	(void) offset;
}

void	render_li_text(t_li *li, t_img *img, t_viewport *offset)
{
	(void) img;
	(void) offset;
	if (li->input_box.has_focus)
		printf("%s: \033[48;2;100;100;100m%s\033[49m\n", li->name,
			li->input_box.input);
	else
		printf("%s: %s\n", li->name, li->input_box.input);
}
