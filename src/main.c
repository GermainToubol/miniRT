/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:52:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/27 11:49:10 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	run(t_data *data)
{
	(void) data;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret_value;

	ret_value = init(&data, argc, argv);
	if (ret_value != 0)
		return (ret_value);
	ret_value = run(&data);
	terminate(&data);
	return (ret_value);
}
