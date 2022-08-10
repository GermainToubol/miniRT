/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_li.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:13:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/10 03:24:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "menu.h"

void	set_li(t_li *li, t_var_type var_type, void *ptr, char *name)
{
	ft_strlcpy(li->name, name, 16);
	set_input_box(&li->input_box, var_type, ptr);
}
