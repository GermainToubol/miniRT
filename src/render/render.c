/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:54:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 08:26:46 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "events.h"
#include "mlx.h"
#include "mlx_int.h"
#include "minirt.h"
#include "ray.h"
#include "render.h"
#include "scene.h"

void	set_ray(t_ray *ray, t_camera *camera, int x, int y)
{
	ray->pos = camera->pos;
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

	img = (t_img *) frame_buffer;
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
	t_ray	ray;
	t_color	color;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			set_ray(&ray, data->scene.camera, x, y);
			if (set_color(&color, &ray, data) == -1)
				return (-1);
			put_color(x, y, &color, data->frame_buffer);
			y++;
		}
		x++;
		if (data->ui_state.verbose)
			print_progress(x);
	}
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
