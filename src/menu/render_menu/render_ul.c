/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 03:00:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 09:38:52 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "mlx_int.h"

#include <stdio.h>

void	render_ul_background(t_ul *ul, t_img *img, t_viewport *offset)
{
	int	i;

	i = 0;
	while (i < ul->nb_li)
	{
		render_li_background(&ul->li[i], img, offset);
		i++;
	}
}

void	render_ul_text(t_ul *ul, t_img *img, t_viewport *offset)
{
	int	i;

	printf("%s\n", ul->name);
	i = 0;
	while (i < ul->nb_li)
	{
		render_li_text(&ul->li[i], img, offset);
		i++;
	}
}
