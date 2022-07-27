/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:57:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 22:00:15 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	size_int(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_positive;
	int		i;

	is_positive = (n >= 0);
	i = size_int(n);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		if (is_positive)
			str[i] = '0' + n % 10;
		else
			str[i] = '0' - n % 10;
		n /= 10;
	}
	if (!is_positive)
		str[0] = '-';
	return (str);
}
