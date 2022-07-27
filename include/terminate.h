/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:55:12 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:30:45 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINATE_H
# define TERMINATE_H

# include "minirt.h"
# include "scene.h"

void	free_scene(t_scene *scene);
void	terminate(t_data *data);
void	terminate_mlx(t_data *data);

#endif
