/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_contribution.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:16:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/18 22:23:19 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_CONTRIBUTION_H
# define LIGHT_CONTRIBUTION_H

# include "intersection.h"
# include "minirt.h"
# include "scene.h"

# define BRIGHTNESS 1000
# define RATIO -1.2f
# define D_SCALE 200.f

int		set_light_contribution(t_color *color, float *ratio,
			t_intersection *intersection, t_data *data);
int		set_ambient_light_contribution(t_color *color,
			float *ratio, t_intersection *intersection, t_data *data);
int		set_direct_light_contribution(t_color *color,
			float *ratio, t_intersection *intersection, t_data *data);
float	set_specular_contribution(t_intersection *intersection, float *ratio,
			t_vect *intersect_light, t_light *light);
#endif /* LIGHT_CONTRIBUTION_H */
