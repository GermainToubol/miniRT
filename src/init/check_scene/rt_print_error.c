/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:46:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 19:52:17 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"

int	rt_print_error(const char *str_error, char **elem, int i_error_elem)
{
	int	i;

	ft_putstr_fd((char *) str_error, 2);
	i = 0;
	while (elem[i])
	{
		if (i == i_error_elem)
			ft_putstr_fd(ANSI_SGR_UNDERLINE, 2);
		ft_putstr_fd(elem[i], 2);
		if (i == i_error_elem)
			ft_putstr_fd(ANSI_SGR_RESET, 2);
		i++;
		if (elem[i])
			ft_putchar_fd(' ', 2);
	}
	ft_putchar_fd('\n', 2);
	return (1);
}
