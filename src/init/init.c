/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:09:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 14:51:49 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "init.h"
#include "minirt.h"
#include "terminate.h"

static int	check_input(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		return (ft_putstr_fd("Too few arguments\n", 2), -1);
	if (argc > 2)
		return (ft_putstr_fd("Too many arguments\n", 2), -1);
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	if (check_input(argc, argv) == -1)
		return (2);
	if (init_scene(data, argc, argv) == -1)
		return (1);
	if (init_mlx(data) == -1)
		return (free_scene(&data->scene), 1);
	return (0);
}
