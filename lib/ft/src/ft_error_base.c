/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:12:50 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:26:34 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_error_base(char *base)
{
	size_t	len_base;
	size_t	i;
	size_t	j;

	if (!base)
		return (1);
	len_base = ft_strlen(base);
	if (len_base <= 1)
		return (1);
	i = 0;
	while (i < len_base)
	{
		if (!ft_isprint(base[i]))
			return (1);
		j = i + 1;
		while (j < len_base)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
