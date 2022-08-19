/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_set_elem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:57:47 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 10:36:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft.h"
#include "init.h"
#include "parse_tiff.h"
#include "scene.h"

int	rt_set_cylinder(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_cylinder	*cylinder;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	ft_strlcpy(obj->name, "Cylinder XXX", 16);
	obj->tag = cylinder_tag;
	cylinder = &obj->cylinder;
	cylinder->pos = rt_get_pos(elem[1]);
	cylinder->dir = rt_get_dir(elem[2]);
	cylinder->r = rt_get_diameter(elem[3]) / 2;
	cylinder->h = rt_get_height(elem[4]);
	obj->color = rt_get_color(elem[5]);
	obj->texture = rt_get_texture(scene, elem, 6);
	obj->bumpmap = rt_get_bumpmap(scene, elem, 7);
	obj->checkerboard = rt_get_checkerboard(elem, 8);
	return (0);
}

int	rt_set_triangle(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_triangle	*triangle;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	ft_strlcpy(obj->name, "Triangle XXX", 16);
	obj->tag = triangle_tag;
	triangle = &obj->triangle;
	triangle->edge[0] = rt_get_pos(elem[1]);
	triangle->edge[1] = rt_get_pos(elem[2]);
	triangle->edge[2] = rt_get_pos(elem[3]);
	obj->color = rt_get_color(elem[4]);
	obj->texture = rt_get_texture(scene, elem, 5);
	obj->bumpmap = rt_get_bumpmap(scene, elem, 6);
	obj->checkerboard = rt_get_checkerboard(elem, 7);
	return (0);
}

int	rt_set_hyperbol(t_scene *scene, char **elem, int *i_elem_category)
{
	t_obj		*obj;
	t_hyperbol	*hyperbol;

	obj = scene->obj + i_elem_category[0];
	i_elem_category[0] += 1;
	ft_strlcpy(obj->name, "Hyperbol XXX", 16);
	obj->tag = hyperbol_tag;
	hyperbol = &obj->hyperbol;
	hyperbol->pos = rt_get_pos(elem[1]);
	hyperbol->dir = rt_get_dir(elem[2]);
	hyperbol->r = rt_get_diameter(elem[3]) / 2;
	hyperbol->h = rt_get_height(elem[4]);
	obj->color = rt_get_color(elem[5]);
	obj->texture = rt_get_texture(scene, elem, 6);
	obj->bumpmap = rt_get_bumpmap(scene, elem, 7);
	obj->checkerboard = rt_get_checkerboard(elem, 8);
	return (0);
}

int	rt_set_texture(t_scene *scene, char **elem, int *i_elem_category)
{
	t_texture	*texture;
	t_tiff_img	img;
	int			i;
	int			size;

	texture = scene->texture + i_elem_category[3];
	i_elem_category[3] += 1;
	if (load_tiff_img(elem[1], &img) != 0)
		return (-1);
	size = (int32_t)img.width * (int32_t)img.height;
	texture->img = ft_calloc(size, sizeof(t_color));
	if (texture->img == NULL)
		return (free(img.content), -1);
	texture->width = img.width;
	texture->height = img.height;
	i = -1;
	while (++i < size)
	{
		texture->img[i].r = (float)(int)img.content[3 * i] / 255.0f;
		texture->img[i].g = (float)(int)img.content[3 * i + 1] / 255.0f;
		texture->img[i].b = (float)(int)img.content[3 * i + 2] / 255.0f;
	}
	free(img.content);
	return (0);
}

int	rt_set_bumpmap(t_scene *scene, char **elem, int *i_elem_category)
{
	t_bumpmap	*bumpmap;
	t_tiff_img	img;
	int			i;
	int			size;

	bumpmap = scene->bumpmap + i_elem_category[4];
	i_elem_category[4] += 1;
	if (load_tiff_img(elem[1], &img) != 0)
		return (-1);
	size = (int32_t)img.width * (int32_t)img.height;
	bumpmap->img = ft_calloc(size, sizeof(float));
	if (bumpmap->img == NULL)
		return (free(img.content), -1);
	bumpmap->width = img.width;
	bumpmap->height = img.height;
	i = -1;
	while (++i < size)
		bumpmap->img[i] = ((float)img.content[3 * i] + 126.0f) / 255.f;
	free(img.content);
	return (0);
}
