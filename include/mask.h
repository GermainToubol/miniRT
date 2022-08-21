/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:38:15 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/21 17:38:45 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASK_H
# define MASK_H

# include "scene.h"
# include "t_math.h"

/*
  The mask contain the direction of the ray comming from the object and
  transpercing the light sphere. It also contains an information about the solid
  angle theta of the object : cos(theta/2) -> allows to compare easaly if the
  object will intersect using a dot product.
 */

typedef void	(*t_mask_func)(t_mask *, t_obj *, t_pos *);

//	set_mask
void	set_coneview_sphere(t_mask *mask, t_pos *pos_relative_origin,
			float d2_obj_origin, float r2_sphere);
void	set_d2_bounds_sphere(t_mask *mask, float d2_obj_origin,
			float r2_sphere);

void	set_cylinder_mask(t_mask *mask, t_obj *obj, t_pos *origin);
void	set_default_mask(t_mask *mask, t_obj *obj, t_pos *origin);
void	set_plane_mask(t_mask *mask, t_obj *obj, t_pos *origin);
void	set_sphere_mask(t_mask *mask, t_obj *obj, t_pos *origin);
void	set_triangle_mask(t_mask *mask, t_obj *obj, t_pos *origin);

//	update_mask_camera
void	update_mask_camera(t_mask *mask, t_camera *camera,
			t_obj *obj);
void	update_mask_cameras(t_scene *scene, int n);
void	update_masks_camera(t_camera *camera, t_scene *scene);
void	update_masks_cameras(t_scene *scene);

//	update_mask_light
void	update_mask_light(t_mask *mask, t_light *light,
			t_obj *obj);
void	update_mask_lights(t_scene *scene, int n);
void	update_masks_light(t_light *light, t_scene *scene);
void	update_masks_lights(t_scene *scene);

#endif /* RASTER_H */
