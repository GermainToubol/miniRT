/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:43:56 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:32:01 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "minirt.h"

int	init(t_data *data, int argc, char **argv);
int	init_mlx(t_data *data);
int	init_scene(t_data *data, int argc, char **argv);

//	CHECK_SCENE
int	check_scene(char **scene_lines);

//	PARSE_SCENE
int	parse_scene(t_scene *scene, char **scene_lines);

#endif
