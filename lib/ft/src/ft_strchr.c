/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:37:52 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:40:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	char_searched;
	int				i;

	char_searched = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == char_searched)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == char_searched)
		return ((char *) s + i);
	return (0);
}
