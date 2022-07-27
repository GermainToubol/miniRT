/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:29:59 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:29:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	len_sub_string;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len_sub_string = 0;
	else if (len < ft_strlen(s) - start)
		len_sub_string = len;
	else
		len_sub_string = ft_strlen(s) - start;
	sub_string = malloc(len_sub_string + 1);
	if (!sub_string)
		return (0);
	i = 0;
	while (i < len_sub_string)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
