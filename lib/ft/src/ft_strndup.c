/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:21:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/01 03:23:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, int size)
{
	char	*copy;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	if (len_s < size)
		size = len_s;
	copy = malloc(size + 1);
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
