/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:59:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/03 17:28:14 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*addr1;
	unsigned char	*addr2;
	size_t			i;

	if (n == 0)
		return (0);
	addr1 = (unsigned char *) s1;
	addr2 = (unsigned char *) s2;
	i = 0;
	while (i + 1 < n && addr1[i] == addr2[i])
		i++;
	return ((int) addr1[i] - (int) addr2[i]);
}
