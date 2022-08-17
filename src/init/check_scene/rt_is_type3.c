/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_is_type3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:23:30 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/17 13:45:51 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	rt_is_texture_id(char *str)
{
	return (ft_isint(str));
}

int	rt_is_bumpmap_id(char *str)
{
	return (ft_isint(str));
}

int	rt_is_checkerboard(char *str)
{
	return (ft_isint(str));
}
