/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:37:24 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 19:51:00 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	nbr;
	double	exponent;
	int		i;

	nbr = (double) ft_atoi(str);
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
