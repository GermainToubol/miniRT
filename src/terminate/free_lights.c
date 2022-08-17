/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:33:01 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/17 15:37:16 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scene.h"
#include "terminate.h"

void	free_lights(t_light *light, int nb_lights)
{
	int	i;

	if (light == NULL)
		return ;
	i = -1;
	while (++i < nb_lights)
		free(light[i].mask);
	free(light);
}
