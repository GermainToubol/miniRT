/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:31:24 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 15:33:41 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"

void	free_camera(t_camera *camera, int nb_cameras)
{
	int	i;

	if (camera == NULL)
		return ;
	i = -1;
	while (++i < nb_cameras)
		free(camera[i].mask);
	free(camera);
}
