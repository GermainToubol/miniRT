/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 08:01:31 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "ray.h"
# include "scene.h"

void	print_progress(int x);
int		render(t_data *data);
int		set_color(t_color *color, t_ray *ray, t_data *data);
void	set_ray(t_ray *ray, t_camera *camera, int x, int y);

#endif
