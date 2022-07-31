/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:37:24 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 19:51:31 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	float	nbr;
	float	exponent;
	int		i;

	nbr = (float) ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	exponent = 0.1;
	if (str[i])
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr += (str[i] - '0') * exponent;
		exponent *= 0.1;
		i++;
	}
	return (nbr);
}
