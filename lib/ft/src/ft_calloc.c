/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:21:58 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/11 01:28:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*addr;
	size_t			i;

	addr = malloc(nmemb * size);
	if (!addr)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		addr[i] = 0;
		i++;
	}
	return ((void *) addr);
}
