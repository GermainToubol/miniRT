/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_scene_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:05:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/07 21:07:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "scene.h"

static void	putnbr_to_end(char *str, int nbr)
{
	char	buffer[4];
	int		end;
	int		i;

	ft_memset(buffer, 0, 4);
	i = 3;
	while (i && (i == 3 || nbr != 0))
	{
		i--;
		buffer[i] = '0' + nbr % 10;
		nbr /= 10;
	}
	end = ft_strlen(str);
	ft_memcpy(str + end - 3, buffer + i, 4 - i);
}

static void	name_scene_objs(t_scene *scene)
{
	char		*name;
	t_obj_tag	tag;
	static int	i_obj[3] = {0};
	int			i;

	i = 0;
	while (i < scene->nb_objs)
	{
		name = scene->obj[i].name;
		tag = scene->obj[i].tag;
		i_obj[tag] += 1;
		putnbr_to_end(name, i_obj[tag]);
		i++;
	}
}

static void	name_scene_lights(t_scene *scene)
{
	char		*name;
	int			i;

	i = 0;
	while (i < scene->nb_lights)
	{
		name = scene->light[i].name;
		i++;
		putnbr_to_end(name, i);
	}
}

static void	name_scene_cameras(t_scene *scene)
{
	char		*name;
	int			i;

	i = 0;
	while (i < scene->nb_cameras)
	{
		name = scene->camera[i].name;
		i++;
		putnbr_to_end(name, i);
	}
}

void	name_scene_elems(t_scene *scene)
{
	name_scene_objs(scene);
	name_scene_lights(scene);
	name_scene_cameras(scene);
}
