/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:54:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 17:41:07 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "events.h"
#include "mask.h"
#include "mlx.h"
#include "mlx_int.h"
#include "minirt.h"
#include "render.h"
#include "scene.h"

#include <stdio.h>
#include <sys/time.h>

void	set_ray(t_ray *ray, t_camera *camera, int x, int y)
{
	ray->dir = camera->anchor;
	ray->dir = v_add(ray->dir, v_scalar((float) x, camera->ux));
	ray->dir = v_add(ray->dir, v_scalar((float) -y, camera->uy));
	ray->dir = v_sub(ray->dir, camera->pos);
	v_normalize(&ray->dir);
}

static void	put_color(int x, int y, t_color *color, void *frame_buffer)
{
	t_img				*img;
	unsigned int		color_int;
	int					pos;

	img = (t_img *)frame_buffer;
	color_int = (unsigned char)((1 - expf(color->r)) * 255.0f);
	color_int = color_int << 8;
	color_int += (unsigned char)((1 - expf(color->g)) * 255.0f);
	color_int = color_int << 8;
	color_int += (unsigned char)((1 - expf(color->b)) * 255.0f);
	pos = (y * img->size_line + x * (img->bpp / 8));
	*((unsigned int *)(img->data + pos)) = color_int;
}

static int	set_image(t_data *data)
{
	t_ray			ray;
	t_color			color;
	int				x;
	int				y;
	struct timeval	start;
	struct timeval	end;
	double			time_taken;

	y = 0;
	gettimeofday(&start, NULL);
	update_masks_camera(data->scene.camera, &data->scene);
	update_masks_lights(&data->scene);
	ray.pos = data->scene.camera->pos;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_ray(&ray, data->scene.camera, x, y);
			if (set_color(&color, &ray, data) == -1)
				return (-1);
			put_color(x, y, &color, data->frame_buffer);
			x++;
		}
		y++;
		if (data->ui_state.verbose)
			print_progress(y, HEIGHT);
	}
	gettimeofday(&end, NULL);
	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-3;
	if (data->ui_state.verbose)
		printf("loop: %.1f ms\n", time_taken);
	return (0);
}

int	render(t_data *data)
{
	if (data->ui_state.to_render == 0)
		return (0);
	data->ui_state.to_render = 0;
	if (set_image(data) == -1)
		return (close_window(data), 1);
	mlx_put_image_to_window(data->mlx, data->win, data->frame_buffer, 0, 0);
	return (0);
}
