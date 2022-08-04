/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:56:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 19:09:36 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parameters.h"
# include "t_math.h"

typedef t_vect	t_pos;
typedef t_vect	t_dir;

typedef struct s_sphere
{
	t_pos	pos;
	float	r;
}	t_sphere;

typedef struct s_plane
{
	t_pos	pos;
	t_dir	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	t_dir	dir;
	float	r;
	float	h;
}	t_cylinder;

typedef struct s_triangle
{
	t_pos	edge[3];
	t_dir	normal;
}	t_triangle;

typedef enum e_obj_tag
{
	sphere_tag,
	plane_tag,
	cylinder_tag,
	triangle_tag
}	t_obj_tag;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_obj
{
	t_obj_tag	tag;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_triangle	triangle;
	};
	t_color		color;
}	t_obj;

typedef struct s_light
{
	t_pos	pos;
	float	ratio;
	t_color	color;
}	t_light;

typedef struct s_ambient_light
{
	float	ratio;
	t_color	color;
}	t_ambient_light;

typedef struct s_camera
{
	t_pos	pos;
	t_dir	dir;
	float	fov;
	t_pos	anchor;
	t_vect	ux;
	t_vect	uy;
}	t_camera;

typedef struct s_scene
{
	int				nb_objs;
	t_obj			*obj;
	int				nb_lights;
	t_light			*light;
	t_ambient_light	ambient_light;
	int				nb_cameras;
	t_camera		*camera;
}	t_scene;

#endif
