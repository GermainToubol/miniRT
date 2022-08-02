/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:24:10 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"
# include "render.h"

typedef struct s_keypress_correspondance
{
	int	keysym;
	int	(*manage_keypress)(t_data *);
}	t_keypress_correspondance;

int	close_window(t_data *data);
int	manage_keypress(int keysym, t_data *data);

//	move
int	move_down(t_data *data);
int	move_left(t_data *data);
int	move_right(t_data *data);
int	move_up(t_data *data);

#endif
