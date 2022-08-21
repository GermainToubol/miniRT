/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:56:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 17:36:48 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "t_math.h"

typedef struct s_data	t_data;
typedef t_vect			t_pos;
typedef t_vect			t_dir;

typedef struct s_sphere
{
	t_pos	pos;
	float	r;
}	t_sphere;

typedef struct s_plane
{
	t_pos	pos;
	t_dir	normal;
	t_dir	ux;
	t_dir	uy;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	t_dir	dir;
	float	r;
	float	h;
	t_dir	ux;
	t_dir	uy;
	t_pos	up_face;
	t_pos	down_face;
}	t_cylinder;

typedef struct s_triangle
{
	t_pos	edge[3];
	t_dir	normal;
	t_dir	ux;
	t_dir	uy;
}	t_triangle;

typedef struct s_hyperbol
{
	t_pos	pos;
	t_dir	dir;
	float	r;
	float	h;
	t_dir	ux;
	t_dir	uy;
}	t_hyperbol;


typedef enum e_obj_tag
{
	sphere_tag,
	plane_tag,
	cylinder_tag,
	triangle_tag,
	hyperbol_tag
}	t_obj_tag;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_texture
{
	t_color	*img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_bumpmap
{
	float	*img;
	int		width;
	int		height;
}	t_bumpmap;

typedef struct s_obj
{
	char		name[16];
	t_obj_tag	tag;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_triangle	triangle;
		t_hyperbol	hyperbol;
	};
	t_color		color;
	t_texture	*texture;
	t_bumpmap	*bumpmap;
	int			checkerboard;
}	t_obj;

typedef struct s_mask
{
	t_dir	dir;
	float	angle;
	float	d2_majorant;
	float	d2_minorant;
}	t_mask;

typedef struct s_light
{
	char	name[16];
	t_pos	pos;
	float	ratio;
	t_color	color;
	t_mask	*mask;
}	t_light;

typedef struct s_ambient_light
{
	char	name[16];
	float	ratio;
	t_color	color;
}	t_ambient_light;

typedef struct s_camera
{
	char	name[16];
	t_pos	pos;
	t_dir	dir;
	float	fov;
	t_pos	anchor;
	float	theta;
	t_vect	ux;
	t_vect	uy;
	t_mask	*mask;
}	t_camera;

typedef struct s_scene
{
	int				nb_objs;
	t_obj			*obj;
	int				nb_lights;
	t_light			*light;
	int				nb_ambient_lights;
	t_ambient_light	*ambient_light;
	int				nb_cameras;
	t_camera		*camera;
	int				nb_textures;
	t_texture		*texture;
	int				nb_bumpmaps;
	t_bumpmap		*bumpmap;
}	t_scene;

#endif
