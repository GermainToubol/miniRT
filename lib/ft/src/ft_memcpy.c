/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:50:43 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:40:43 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*addr_dest;
	unsigned char	*addr_src;
	size_t			i;

	addr_dest = (unsigned char *) dest;
	addr_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		addr_dest[i] = addr_src[i];
		i++;
	}
	return (dest);
}
