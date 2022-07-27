/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:27:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/02 21:11:58 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*addr;
	size_t			i;

	addr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		addr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
