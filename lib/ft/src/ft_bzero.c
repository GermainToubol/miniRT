/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:45:52 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 13:28:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*addr;
	size_t			i;

	addr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		addr[i] = 0;
		i++;
	}
}
