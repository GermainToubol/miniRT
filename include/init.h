/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:43:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 19:14:44 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "minirt.h"
# include "scene.h"

# define RT_AMBIENT_LIGHT "A"
# define RT_CAMERA "C"
# define RT_LIGHT "l"
# define RT_SPHERE "sp"
# define RT_PLANE "pl"
# define RT_CYLINDER "cy"
# define RT_TRIANGLE "tr"

int		init(t_data *data, int argc, char **argv);
int		init_mlx(t_data *data);
int		init_scene(t_scene *scene, int argc, char **argv);
void	init_scene_derivates(t_scene *scene);

//	CHECK_SCENE

# define ERROR_TOO_FEW_PARAMS "Error format: Too few parameters\n"
# define ERROR_TOO_MANY_PARAMS "Error format: Too many parameters\n"
# define ERROR_MULTIPLE_UNIQUE_ELEM "Error format: Unique element defined\
 multiple times\n"
# define ERROR_WRONG_ELEM_TYPE "Error format: Element type not recognized\n"
# define ANSI_SGR_RESET "\033[0m"
# define ANSI_SGR_UNDERLINE "\033[4m"

int		check_scene(char **scene_lines);
//	rt_error_elem
int		rt_error_ambient_light_format(char **elem);
int		rt_error_camera_format(char **elem);
int		rt_error_light_format(char **elem);
int		rt_error_sphere_format(char **elem);
int		rt_error_plane_format(char **elem);
int		rt_error_cylinder_format(char **elem);
int		rt_error_triangle_format(char **elem);
//	rt_is_type
int		rt_is_pos(char *str);
int		rt_is_dir(char *str);
int		rt_is_color(char *str);
int		rt_is_ratio(char *str);
int		rt_is_fov(char *str);
int		rt_is_diameter(char *str);
int		rt_is_height(char *str);
//	rt_print_error
int		rt_print_error(const char *str_error, char **elem, int i_error_elem);

//	PARSE_SCENE

int		parse_scene(t_scene *scene, char **scene_lines);
//	rt_set_elem
int		rt_set_ambient_light(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_camera(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_light(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_sphere(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_plane(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_cylinder(t_scene *scene, char **elem, int *i_elem_category);
int		rt_set_triangle(t_scene *scene, char **elem, int *i_elem_category);
//rt_get_type
t_vect	rt_get_pos(char *str);
t_vect	rt_get_dir(char *str);
t_color	rt_get_color(char *str);
float	rt_get_ratio(char *str);
float	rt_get_fov(char *str);
float	rt_get_diameter(char *str);
float	rt_get_height(char *str);

#endif
