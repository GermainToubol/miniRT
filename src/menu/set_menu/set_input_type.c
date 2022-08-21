/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:56:25 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 23:13:39 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "t_math.h"

void	set_input_int(char *input, void *ptr)
{
	int		nbr;
	char	buffer[10];
	int		sign;
	int		i;

	ft_memset(input, 0, 16);
	nbr = *((int *) ptr);
	sign = 1 - 2 * (nbr < 0);
	i = 10;
	while (i == 10 || nbr != 0)
	{
		buffer[--i] = '0' + sign * nbr % 10;
		nbr /= 10;
	}
	if (sign < 0)
		buffer[--i] = '-';
	ft_memcpy(input, buffer + i, 10 - i);
}

void	set_input_float(char *input, void *ptr)
{
	float	f;
	int		f_int;
	int		len;
	int		i;

	f = *((float *) ptr);
	f_int = (int) f;
	if (f < 0 && f_int == 0)
		ft_strlcpy(input, "-0", 16);
	else
		set_input_int(input, &f_int);
	f -= f_int;
	f = f_abs(f);
	len = ft_strlen(input);
	input[len] = '.';
	i = 0;
	while (i++ < 3)
	{
		f *= 10;
		input[len + i] = '0' + (int) f;
		f -= (int) f;
	}
	input[len + i] = 0;
}

void	set_input_str(char *str, void *ptr)
{
	char	*str_val;

	str_val = (char *) ptr;
	ft_strlcpy(str, str_val, 16);
}
