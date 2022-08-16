/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_input_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:41:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/16 22:55:23 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	update_input_int(char *input, void *ptr)
{
	int	*val;

	if (!ft_isint(input))
		return (2);
	val = (int *) ptr;
	*val = ft_atoi(input);
	return (0);
}

int	update_input_float(char *input, void *ptr)
{
	float	*val;

	if (!ft_isfloat(input))
		return (2);
	val = (float *) ptr;
	*val = ft_atof(input);
	return (0);
}

int	update_input_ratio(char *input, void *ptr)
{
	float	f;
	float	*val;

	if (!ft_isfloat(input))
		return (2);
	f = ft_atof(input);
	if (f < 0 || f > 1)
		return (2);
	val = (float *) ptr;
	*val = f;
	return (0);
}

int	update_input_fov(char *input, void *ptr)
{
	float	f;
	float	*val;

	if (!ft_isfloat(input))
		return (2);
	f = ft_atof(input);
	if (f < 0 || f > 180)
		return (2);
	val = (float *) ptr;
	*val = f;
	return (0);
}

int	update_input_str(char *input, void *ptr)
{
	if (ft_strlen(input) >= 16)
		return (2);
	ft_strlcpy(ptr, input, 16);
	return (0);
}
