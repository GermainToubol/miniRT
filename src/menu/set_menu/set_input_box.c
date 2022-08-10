/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:54 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/10 04:25:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

void	set_input_box(t_input_box *input_box, t_var_type var_type, void *ptr)
{
	static void	(*set_input_type[])(char *, void *) = {set_input_int,
		set_input_float, set_input_float, set_input_float, set_input_str};

	(set_input_type[var_type])(input_box->input, ptr);
	input_box->type = var_type;
	input_box->ptr = ptr;
}
