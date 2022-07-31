/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:46:41 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/31 20:20:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, const char *delim)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(delim, s[i]) != NULL)
			i++;
		if (s[i])
			count++;
		while (s[i] && ft_strchr(delim, s[i]) == NULL)
			i++;
	}
	return (count);
}

static char	*get_word(char const *s, const char *delim)
{
	char	*word;
	int		j;

	j = 0;
	while (s[j] && ft_strchr(delim, s[j]) == NULL)
		j++;
	word = malloc(j + 1);
	if (!word)
		return (0);
	j = 0;
	while (s[j] && ft_strchr(delim, s[j]) == NULL)
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

char	**ft_split(char const *s, const char *delim)
{
	char	**strs;
	int		i_word;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (count_words(s, delim) + 1));
	if (!strs)
		return (0);
	i_word = 0;
	while (*s)
	{
		while (*s && ft_strchr(delim, *s) != NULL)
			s++;
		if (*s)
		{
			strs[i_word] = get_word(s, delim);
			if (!strs[i_word])
				return (free_strs(strs, i_word));
			i_word++;
		}
		while (*s && ft_strchr(delim, *s) == NULL)
			s++;
	}
	strs[i_word] = 0;
	return (strs);
}
