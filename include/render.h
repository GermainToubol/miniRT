/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/23 18:53:26 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "scene.h"

//	INTERSECTION
# define SHIFT 0.001f

//	LIGHT_CONTRIBUTION
# define BRIGHTNESS 1000
# define RATIO -1.2f
# define D_SCALE 200.f

typedef struct s_ray
{
	t_pos	pos;
	t_dir	dir;
}	t_ray;

typedef struct s_intersection
{
	t_pos	pos;
	t_dir	norm;
	t_color	color_absorption;
	t_ray	*ray;
	t_obj	*obj_seen;
	t_color	specular;
	int		on_face;
}	t_intersection;

void	print_progress(int x, int max);
int		render(t_data *data);
int		set_color(t_color *color, t_ray *ray, t_data *data);
void	set_ray(t_ray *ray, t_camera *camera, int x, int y);

//	INTERSECTION

typedef float	(*t_intersection_func) (t_obj *, t_ray *);
typedef int		(*t_normal_func) (t_ray *, t_pos *, t_dir *, t_obj *);

int		set_intersection(t_intersection *intersection, t_ray *ray,
			t_data *data);

/* Intersection Position */
int		set_intersection_pos(t_pos *pos, t_obj **obj_seen, t_ray *ray,
			t_data *data);

float	set_intersection_sphere(t_obj *obj, t_ray *ray);
float	set_intersection_plane(t_obj *obj, t_ray *ray);
float	set_intersection_cylinder(t_obj *obj, t_ray *ray);
float	set_intersection_triangle(t_obj *obj, t_ray *ray);
float	set_intersection_hyperbol(t_obj *obj, t_ray *ray);

/* Intersection Normal */
int		set_intersection_normal(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);

int		set_normal_sphere(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);
int		set_normal_plane(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);
int		set_normal_cylinder(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);
int		set_normal_triangle(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);
int		set_normal_hyperbol(t_ray *ray, t_pos *pos, t_dir *normal,
			t_obj *obj_seen);

//	LIGHT_CONTRIBUTION

int		set_light_contribution(t_color *color, float *ratio,
			t_intersection *intersection, t_data *data);
int		set_ambient_light_contribution(t_color *color,
			float *ratio, t_intersection *intersection, t_data *data);
int		set_direct_light_contribution(t_color *color,
			float *ratio, t_intersection *intersection, t_data *data);
float	set_specular_contribution(t_intersection *intersection, float *ratio,
			t_vect *intersect_light, t_light *light);

//	UPDATE_SCENE

typedef void	(*t_update_obj) (t_obj *, t_camera *);

int		update_camera(t_camera *camera, t_scene *scene);
void	update_cylinder(t_obj *obj, t_camera *cam);
void	update_hyperbol(t_obj *obj, t_camera *cam);
int		update_light(t_light *light, t_scene *scene);
void	update_plane(t_obj *obj, t_camera *cam);
void	update_scene(t_scene *scene);
void	update_sphere(t_obj *obj, t_camera *cam);
void	update_triangle(t_obj *obj, t_camera *cam);

#endif
