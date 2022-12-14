/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:36:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 19:37:57 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memset_int(int *tab, int val, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		tab[i] = val;
		i++;
	}
}
