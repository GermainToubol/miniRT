/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derivates.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:01 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/11 14:01:55 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVATES_H
# define DERIVATES_H

# include "scene.h"

typedef void	(*t_derivate_func) (t_obj *);

void	init_sphere_derivates(t_obj *obj);
void	init_plane_derivates(t_obj *obj);
void	init_cylinder_derivates(t_obj *obj);
void	init_triangle_derivates(t_obj *obj);

#endif /* DERIVATES_H */
