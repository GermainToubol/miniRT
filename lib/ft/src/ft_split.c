/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:46:41 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/05/04 20:53:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char delim)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delim)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != delim)
			i++;
	}
	return (count);
}

static char	*get_word(char const *s, char delim)
{
	char	*word;
	int		j;

	j = 0;
	while (s[j] && s[j] != delim)
		j++;
	word = malloc(j + 1);
	if (!word)
		return (0);
	j = 0;
	while (s[j] && s[j] != delim)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**free_strs(char **strs, int i_word)
{
	int	i;

	i = 0;
	while (i < i_word)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i_word;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (0);
	i_word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strs[i_word] = get_word(s, c);
			if (!strs[i_word])
				return (free_strs(strs, i_word));
			i_word++;
		}
		while (*s && *s != c)
			s++;
	}
	strs[i_word] = 0;
	return (strs);
}
