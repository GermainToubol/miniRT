/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:50:33 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 13:46:37 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*addr;
	unsigned char	char_searched;
	size_t			i;

	addr = (unsigned char *) s;
	char_searched = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (addr[i] == char_searched)
			return (addr + i);
		i++;
	}
	return (0);
}
