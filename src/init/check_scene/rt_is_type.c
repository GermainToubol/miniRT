/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:48:53 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/19 14:26:18 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"

static int	rt_is_vect(char *str)
{
	int	dot_seen;
	int	i;

	i = 0;
	while (i++ < 3)
	{
		if (*str == '+' || *str == '-')
			str++;
		dot_seen = 0;
		while (*str && *str != ',')
		{
			if ((!ft_isdigit(*str) && *str != '.')
				|| (dot_seen && *str == '.'))
				return (0);
			dot_seen |= (*str == '.');
			str++;
		}
		if ((i < 3 && !*str)
			|| (i == 3 && *str))
			return (0);
		if (*str)
			str++;
	}
	return (1);
}

int	rt_is_pos(char *str)
{
	return (rt_is_vect(str));
}

int	rt_is_dir(char *str)
{
	t_vect	v;

	if (!rt_is_vect(str))
		return (0);
	v = rt_get_dir(str);
	if (v.x < -1 || v.x > 1
		|| v.y < -1 || v.y > 1
		|| v.z < -1 || v.z > 1)
		return (0);
	return (1);
}

int	rt_is_color(char *str)
{
	int	x;
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (str[j] && str[j] != ',')
		{
			if (!ft_isdigit(str[j]))
				return (0);
			j++;
		}
		if (j == 0 || j > 3 || (!str[j] && i < 2))
			return (0);
		x = ft_atoi(str);
		if (x >= 256)
			return (0);
		str += j + 1;
		i++;
	}
	return (1);
}
