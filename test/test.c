/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:32:19 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/16 17:46:56 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int	main(void)
{
	float	tab[100000];
	int	tabi[100000];
	int	i;
	float	result;
	int	resulti;
	struct timeval start, end;
	double time_taken;

	srand(123497);
	i = 0;
	while (i < 100000)
		tab[i++] = 1 + (float)rand()/(float)(RAND_MAX);
	result = 0;
	i = 0;
	gettimeofday(&start, NULL);
	while (i < 100000)
		result *= tab[i++];
	gettimeofday(&end, NULL);
	printf("result float: %f\n", result);

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec -
                              start.tv_usec)) * 1e-6;
	printf("loop float: %f ms\n", time_taken);
	i = 0;
	while (i < 100000)
		tabi[i++] = rand();
	result = 0;
	i = 0;
	gettimeofday(&start, NULL);
	while (i < 100000)
	{
		resulti *= tabi[i++];
		resulti >>= 8;
	}
	gettimeofday(&end, NULL);
	printf("result int: %i\n", resulti);

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec -
                              start.tv_usec)) * 1e-6;
	printf("loop int: %f ms\n", time_taken);

	return (0);
}
