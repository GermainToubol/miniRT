/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:11:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:59:29 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	is_positive;
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	is_positive = !(nptr[i] == '-');
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	nbr = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		if (is_positive)
			nbr += (nptr[i] - '0');
		else
			nbr -= (nptr[i] - '0');
		i++;
	}
	return (nbr);
}
