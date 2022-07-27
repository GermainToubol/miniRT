/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:04:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/07 17:36:36 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little && little[0] == 0)
		return ((char *) big);
	if (!big || !little)
		return (0);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
			j++;
		if (i + j > len)
			break ;
		if (!little[j])
			return ((char *) big + i);
		i++;
	}
	return (0);
}
