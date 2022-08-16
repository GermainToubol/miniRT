/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derivates.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:01 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 11:32:35 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVATES_H
# define DERIVATES_H

# include "scene.h"

typedef void	(*t_derivate_func) (t_obj *);

int		init_light_derivates(t_scene *scene, t_light *light);

void	init_sphere_derivates(t_obj *obj);
void	init_plane_derivates(t_obj *obj);
void	init_cylinder_derivates(t_obj *obj);
void	init_triangle_derivates(t_obj *obj);

#endif /* DERIVATES_H */
