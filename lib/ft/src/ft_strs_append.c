/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:56:45 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 13:12:53 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strs_append(char ***strs, char *str)
{
	int		size;
	char	**strs_appened;
	int		i;

	if (!strs || !str)
		return (-1);
	size = ft_tablen(*strs);
	strs_appened = malloc(sizeof(char *) * (size + 2));
	if (!strs_appened)
		return (-1);
	i = 0;
	while (i < size)
	{
		strs_appened[i] = (*strs)[i];
		i++;
	}
	strs_appened[size] = str;
	strs_appened[size + 1] = NULL;
	free(*strs);
	*strs = strs_appened;
	return (0);
}
