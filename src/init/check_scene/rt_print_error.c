/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:46:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/28 00:48:11 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	rt_print_error(const char *str_error, char **elem, int i_error_elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		if (i == i_error_elem)
			ft_putstr_fd("\e[4m", 2);
		ft_putstr_fd(elem[i], 2);
		if (i == i_error_elem)
			ft_putstr_fd("\e[0m", 2);
		i++;
		if (elem[i])
			ft_putchar_fd(' ', 2);
	}
	ft_putchar_fd('\n', 2);
	ft_putstr_fd((char *) str_error, 2);
	return (1);
}
