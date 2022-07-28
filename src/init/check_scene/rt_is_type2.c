/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_is_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:02:08 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/28 01:04:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	rt_is_ratio(char *str)
{
	return (ft_isdouble(str));
}

int	rt_is_fov(char *str)
{
	double	fov;

	if (!ft_isdouble(str))
		return (0);
	fov = ft_atod(str);
	return (fov > 0 && fov <= 180);
}

int	rt_is_diameter(char *str)
{
	return (ft_isdouble(str));
}

int	rt_is_height(char *str)
{
	return (ft_isdouble(str));
}
