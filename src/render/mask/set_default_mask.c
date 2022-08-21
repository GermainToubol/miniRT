/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:45:25 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 18:01:01 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"

void	set_default_mask(t_mask *mask, t_obj *obj, t_pos *origin)
{
	(void) obj;
	(void) origin;
	mask->dir = (t_vect){0, 0, 1};
	mask->angle = -1;
	mask->d2_majorant = -1;
	mask->d2_minorant = -1;
}
