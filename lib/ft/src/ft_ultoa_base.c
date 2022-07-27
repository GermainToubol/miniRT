/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:48:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:27:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	size_ul_int(unsigned long int n, size_t len_base)
{
	int	size;

	size = 1;
	while (n / len_base != 0)
	{
		n /= len_base;
		size++;
	}
	return (size);
}

char	*ft_ultoa_base(unsigned long int n, char *base)
{
	char	*str;
	size_t	len_base;
	int		i;

	if (ft_error_base(base))
		return (0);
	len_base = ft_strlen(base);
	i = size_ul_int(n, len_base);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = base[n % len_base];
		n /= len_base;
	}
	return (str);
}
