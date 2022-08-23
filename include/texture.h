/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 03:23:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/23 13:17:00 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "render.h"
# include "scene.h"

# define TEXTURE_SCALE 10.0f

typedef int	(*t_cboard)(t_color *, t_intersection *);
typedef int	(*t_ftext)(t_color *, t_intersection *);
typedef int	(*t_fbump)(t_color *, t_intersection *);

int	apply_texture(t_color *color, t_ray *ray, t_intersection *intersection);

/* Simple texture: */
int	ftext_sphere(t_color *color, t_intersection *intersection);
int	ftext_plane(t_color *color, t_intersection *intersection);
int	ftext_cylinder(t_color *color, t_intersection *intersection);
int	ftext_triangle(t_color *color, t_intersection *intersection);
int	ftext_hyperbol(t_color *color, t_intersection *intersection);

/* Simple bumpmaps: */
int	fbump_sphere(t_color *color, t_intersection *intersection);
int	fbump_plane(t_color *color, t_intersection *intersection);
int	fbump_cylinder(t_color *color, t_intersection *intersection);
int	fbump_triangle(t_color *color, t_intersection *intersection);
int	fbump_hyperbol(t_color *color, t_intersection *intersection);

/* Checkboard texture: */

// Description of the number of segments on a sphere: n verticaly
// and 2 n horizontaly
# define SPHERE_PART 5
# define INV_PI 0.3183f

int	cboard_sphere(t_color *color, t_intersection *intersection);
int	cboard_plane(t_color *color, t_intersection *intersection);
int	cboard_cylinder(t_color *color, t_intersection *intersection);
int	cboard_triangle(t_color *color, t_intersection *intersection);
int	cboard_hyperbol(t_color *color, t_intersection *intersection);

#endif /* TEXTURE_H */
