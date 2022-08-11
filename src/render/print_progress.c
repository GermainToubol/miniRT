/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_progress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:48:33 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/11 08:19:38 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parameters.h"

void	print_progress(int x)
{
	static char	str[30] = "[....................] XXX%\n";
	int			p;
	int			i;

	if (str[23] == 'X')
		printf("Rendering...\n");
	else
		printf("\033[1F\033[2K");
	p = 100 * x / WIDTH;
	i = 0;
	while (i++ < p / 5)
		str[i] = '#';
	while (i < 21)
		str[i++] = '.';
	i = 25;
	while (i >= 23)
	{
		if (i != 25 && p == 0)
			str[i] = ' ';
		else
			str[i] = '0' + p % 10;
		i--;
		p /= 10;
	}
	printf("%s", str);
}
