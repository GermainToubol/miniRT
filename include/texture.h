/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 03:23:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 17:55:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "light_contribution.h"
# include "scene.h"

typedef int	(*t_cboard)(t_color *, t_intersection *);

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection);

/* Checkboard texture: */

// Description of the number of segments on a sphere: n verticaly
// and 2 n horizontaly
# define SPHERE_PART 5
# define INV_PI 0.3183f

int	cboard_sphere(t_color *color, t_intersection *intersection);
int	cboard_plane(t_color *color, t_intersection *intersection);
int	cboard_cylinder(t_color *color, t_intersection *intersection);

#endif /* TEXTURE_H */
