/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:14:16 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/01 19:54:50 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "minirt.h"
#include "ray.h"
#include "scene.h"

typedef struct	s_intersection
{
	t_pos	pos;
	t_dir	norm;
	t_color	color_absorption;
	t_obj	*obj_seen;
}	t_intersection;

typedef float (*t_intersection_func) (t_obj *, t_ray *);
typedef int (*t_normal_func) (t_pos *, t_dir *, t_obj *);

int		set_intersection(t_intersection *intersection, t_ray *ray,
			t_data *data);

/* Intersection Position */
int		set_intersection_pos(t_pos *pos, t_obj **obj_seen, t_ray *ray,
			t_data *data);

float	set_intersection_sphere(t_obj *obj, t_ray *ray);

/* Intersection Normal */
int		set_intersection_normal(t_pos *pos, t_dir *normal, t_obj *obj_seen);
int		set_normal_sphere(t_pos *pos, t_dir *normal, t_obj *obj_seen);

#endif /* INTERSECTION_H */