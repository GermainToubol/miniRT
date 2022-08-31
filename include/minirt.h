/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/31 15:48:07 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"
# include "ui_state.h"

# define TITLE "miniRT"
# define WIDTH 720
# define HEIGHT 480

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*frame_buffer;
	t_scene		scene;
	t_ui_state	ui_state;
}	t_data;

#endif
