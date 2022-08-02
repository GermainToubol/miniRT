/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:54:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 15:47:13 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "mlx.h"
#include "mlx_int.h"
#include "minirt.h"
#include "ray.h"
#include "render.h"
#include "scene.h"

static void	set_ray(t_ray *ray, t_camera *camera, int x, int y)
{
	ray->pos = camera->pos;
	ray->dir = camera->anchor;
	ray->dir = v_add(ray->dir, v_scalar((float) x, camera->ux));
	ray->dir = v_add(ray->dir, v_scalar((float) y, camera->uy));
	ray->dir = v_sub(ray->dir, camera->pos);
}

static void	put_color(int x, int y, t_color *color, void *frame_buffer)
{
	t_img				*img;
	unsigned int		color_int;
	int					pos;

	img = (t_img *) frame_buffer;
	color_int = (unsigned char) color->r * 256;
	color_int = color_int << 8;
	color_int += (unsigned char) color->g * 256;
	color_int = color_int << 8;
	color_int += (unsigned char) color->b * 256;
	color_int = color_int >> 8;
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
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->to_render == 0)
		return (0);
	if (set_image(data) == -1)
		return (close_window(data), 1);
	mlx_put_image_to_window(data->mlx, data->win, data->frame_buffer, 0, 0);
	return (0);
}
