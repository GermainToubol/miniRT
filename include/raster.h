/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:38:15 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 13:50:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTER_H
# define RASTER_H

# include "scene.h"
# include "t_math.h"

/*
  The mask contain the direction of the ray comming from the object and
  transpercing the light sphere. It also contains an information about the solid
  angle theta of the object : cos(theta/2) -> allows to compare easaly if the
  object will intersect using a dot product.
 */

void	set_sphere_mask(t_obj *obj, t_light *light, t_mask *mask);
void	set_plane_mask(t_obj *obj, t_light *light, t_mask *mask);
void	set_cylinder_mask(t_obj *obj, t_light *light, t_mask *mask);
void	set_default_mask(t_obj *obj, t_light *light, t_mask *mask);

void	update_single_mask_single_light(t_obj *obj, t_light *light, int n);
void	update_all_masks_single_light(t_scene *scene, t_light *light);
void	update_single_mask_all_lights(t_scene *scene, int n);
void	update_all_masks_all_lights(t_scene *scene);

void	update_mask_camera(t_obj *obj, t_camera *camera, int n);
void	update_masks_camera(t_scene *scene, t_camera *camera);

#endif /* RASTER_H */
