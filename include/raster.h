/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:38:15 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 12:21:54 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTER_H
# define RASTER_H

# include "t_math.h"

/*
  The mask contain the direction of the ray comming from the object and
  transpercing the light sphere. It also contains an information about the solid
  angle theta of the object : cos(theta/2) -> allows to compare easaly if the
  object will intersect using a dot product.
 */

typedef struct s_mask
{
	t_vect	dir;
	float	angle;
}	t_mask;

#endif /* RASTER_H */
