/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:47:06 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 19:48:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	return (str[i] == 0);
}
