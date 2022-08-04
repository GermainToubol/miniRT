/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_contribution.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:16:20 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/04 03:30:34 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_CONTRIBUTION_H
# define LIGHT_CONTRIBUTION_H

# include "intersection.h"
# include "minirt.h"
# include "scene.h"

int	set_light_contribution(t_color *color, float *ratio,
		t_intersection *intersection, t_data *data);
int	set_ambient_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data);
int	set_direct_light_contribution(t_color *color,
		float *ratio, t_intersection *intersection, t_data *data);

#endif /* LIGHT_CONTRIBUTION_H */
