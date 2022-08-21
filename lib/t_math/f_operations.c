/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:32:33 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/21 04:33:47 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	f_abs(float f)
{
	if (f < 0)
		f = -f;
	return (f);
}

float	f_max(float f1, float f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}