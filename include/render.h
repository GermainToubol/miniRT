/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 03:29:39 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "ray.h"
# include "scene.h"

int		set_color(t_color *color, t_ray *ray, t_data *data);
void	set_ray(t_ray *ray, t_camera *camera, int x, int y);
int		render(t_data *data);

#endif
