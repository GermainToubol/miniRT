/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_type3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:33:08 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 15:00:36 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "scene.h"

t_texture	*rt_get_texture(t_scene *scene, char **elem, int i)
{
	int	i_texture;

	if (!elem[i])
		return (NULL);
	i_texture = ft_atoi(elem[i]);
	if (i_texture < 0 || i_texture >= scene->nb_textures)
		return (NULL);
	return (scene->texture + i_texture);
}

t_bumpmap	*rt_get_bumpmap(t_scene *scene, char **elem, int i)
{
	int	i_bumpmap;

	if (!elem[i - 1] || !elem[i])
		return (NULL);
	i_bumpmap = ft_atoi(elem[i]);
	if (i_bumpmap < 0 || i_bumpmap >= scene->nb_bumpmaps)
		return (NULL);
	return (scene->bumpmap + i_bumpmap);
}

int	rt_get_checkerboard(char **elem, int i)
{
	int	is_checkerboard;

	if (!elem[i - 2] || !elem[i - 1] || !elem[i])
		return (0);
	is_checkerboard = ft_atoi(elem[i]);
	if (is_checkerboard == 0)
		return (0);
	return (1);
}
