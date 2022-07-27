/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:56:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:47:42 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parameters.h"
# include "t_math.h"

typedef t_vect t_pos;
typedef t_vect t_dir;

typedef struct
{
	t_pos	origin;
	t_dir	dir;
}	t_ray;

typedef struct
{
	t_pos	pos;
	float	r;
}	t_sphere;

typedef struct
{
	t_pos	pos;
	t_dir	normal;
}	t_plane;

typedef struct
{
	t_pos	pos;
	t_dir	dir;
	float	h;
	float	r;
}	t_cylinder;

typedef enum
{
	sphere,
	plane,
	cylinder
}	t_obj_tag;

typedef struct
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct
{
	t_obj_tag	tag;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	t_color		color;
}	t_obj;

typedef struct
{
	t_pos	pos;
	t_color	color;
	float	ratio;
}	t_light;

typedef struct
{
	t_color	color;
	float	ratio;
}	t_ambient_light;

typedef struct
{
	t_ray			**ray;
	int				nb_objs;
	t_obj			*obj;
	int				nb_lights;
	t_light			*light;
	t_ambient_light	ambient_light;
}	t_scene;

#endif
