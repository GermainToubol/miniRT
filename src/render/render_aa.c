/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:10:01 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/31 09:22:58 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "events.h"
#include "ft.h"
#include "mask.h"
#include "mlx.h"
#include "mlx_int.h"
#include "minirt.h"
#include "render.h"
#include "scene.h"
#include "t_random.h"

#ifdef AALIAS

void	set_ray(t_ray *ray, t_camera *camera, int x, int y)
{
	ray->dir = camera->anchor;
	ray->dir = v_add(ray->dir, v_scalar((float)x + r_randf() - 0.5f,
				camera->ux));
	ray->dir = v_add(ray->dir, v_scalar((float)-y - r_randf() + 0.5f,
				camera->uy));
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

static int	multiray_on_pxl(t_color *color, t_data *data, t_ray *ray,
				t_vect dir)
{
	int		i;
	t_color	tmp;

	*color = (t_color){0.0f, 0.0f, 0.0f};
	i = -1;
	while (++i < AALIAS)
	{
		tmp = (t_color){0.0f, 0.0f, 0.0f};
		set_ray(ray, data->scene.camera, dir.x, dir.y);
		if (set_color(&tmp, ray, data) == -1)
			return (-1);
		color->r += tmp.r;
		color->g += tmp.g;
		color->b += tmp.b;
	}
	color->r /= AALIAS;
	color->g /= AALIAS;
	color->b /= AALIAS;
	return (0);
}

static int	set_image(t_data *data)
{
	t_ray			ray;
	t_color			color;
	int				x;
	int				y;

	y = -1;
	update_scene(&data->scene);
	update_masks_lights(&data->scene);
	ray.pos = data->scene.camera->pos;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (multiray_on_pxl(&color, data, &ray, (t_vect){x, y, 0}) == -1)
				return (-1);
			put_color(x, y, &color, data->frame_buffer);
		}
		if (data->ui_state.verbose)
			print_progress(y, HEIGHT - 1);
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

#endif
