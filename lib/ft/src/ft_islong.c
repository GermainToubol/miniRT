/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:05:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/13 01:16:52 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_islong(const char *str)
{
	int		is_neg;
	size_t	size_int;
	size_t	i;

	is_neg = (str[0] == '-');
	size_int = 0;
	i = 0;
	while (size_int < 19 && ft_isdigit(str[is_neg + i]))
	{
		size_int++;
		i++;
	}
	if (size_int != 19 && str[is_neg + i])
		return (0);
	if (!is_neg
		&& size_int == 19
		&& ft_strncmp(str, "9223372036854775807", 10) > 0)
		return (0);
	if (is_neg
		&& size_int == 19
		&& ft_strncmp(str, "9223372036854775808", 10) > 0)
		return (0);
	return (1);
}
