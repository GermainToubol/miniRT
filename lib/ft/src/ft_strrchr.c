/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:40:50 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:02:25 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*addr_last_find;
	unsigned char	char_searched;

	addr_last_find = 0;
	char_searched = (unsigned char) c;
	while (*s)
	{
		if (*s == char_searched)
			addr_last_find = (char *) s;
		s++;
	}
	if (*s == char_searched)
		addr_last_find = (char *) s;
	return (addr_last_find);
}
