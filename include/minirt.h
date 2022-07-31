/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 18:15:21 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*frame_buffer;
	t_scene	scene;
}	t_data;

#endif
