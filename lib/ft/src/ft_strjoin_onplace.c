/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_onplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:37:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/10 22:25:09 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strjoin_onplace(char **s1, const char *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;

	if (!s1)
		return (-1);
	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(s2);
	s_join = malloc(len_s1 + len_s2 + 1);
	if (s_join)
		*s_join = 0;
	if (s_join && *s1)
		ft_strlcpy(s_join, *s1, len_s1 + 1);
	if (s_join && s2)
		ft_strlcpy(s_join + len_s1, s2, len_s2 + 1);
	if (*s1)
		free(*s1);
	*s1 = s_join;
	if (!*s1)
		return (-1);
	return (0);
}
