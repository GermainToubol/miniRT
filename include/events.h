/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:46:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 15:22:43 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"

typedef struct s_keypress_correspondance
{
	int	keysym;
	int	(*manage_keypress)(t_data *);
}	t_keypress_correspondance;

int	close_window(t_data *data);
int	manage_keypress(int keysym, t_data *data);

#endif
