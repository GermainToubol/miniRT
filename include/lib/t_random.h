/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_random.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:31:53 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/01 12:57:30 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RANDOM_H
# define T_RANDOM_H

# define A 1103515245
# define C 12345

int				r_rand(void);
unsigned int	r_rand_static(unsigned int seed);
float			r_randf(void);
void			r_srand(unsigned int seed);

#endif
