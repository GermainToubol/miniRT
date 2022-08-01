/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:34:54 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 12:55:10 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "t_random.h"

unsigned int	r_rand_static(unsigned int seed)
{
	static unsigned long	nb = 0;
	static int				seed_defined = 0;

	if (!seed_defined)
	{
		nb = seed;
		seed_defined = 1;
	}
	nb = nb * A + C;
	return ((unsigned int) nb);
}

int	r_rand(void)
{
	return ((int) r_rand_static(0));
}
