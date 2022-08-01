/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 20:01:13 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "ray.h"
# include "scene.h"

# define WIDTH 720
# define HEIGHT 480

int	set_color(t_color *color, t_ray *ray, t_data *data);
int	render(t_data *data);

#endif
