/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttonrotate_cam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:06:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:26:28 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "events.h"
#include "render.h"
#include "scene.h"
#include "t_math.h"

void	buttonrotate_cam(int mouse_x, int mouse_y, t_camera *camera,
	t_event_state *event_state)
{
	t_ray			ray;
	t_ray			ray_last;
	t_vect			camera_anchor_relative;

	set_ray(&ray_last, camera, event_state->last_buttonpress_x,
		event_state->last_buttonpress_y);
	set_ray(&ray, camera, mouse_x, mouse_y);
	v_rotate(&camera->dir, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	v_rotate(&camera->ux, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	v_rotate(&camera->uy, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	camera_anchor_relative = v_sub(camera->anchor, camera->pos);
	v_rotate(&camera_anchor_relative, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	camera->anchor = v_add(camera->pos, camera_anchor_relative);
}

void	set_buttonrotate_cam(int mouse_x, int mouse_y,
	t_event_state *event_state)
{
	event_state->last_buttonpress_x = mouse_x;
	event_state->last_buttonpress_y = mouse_y;
}
