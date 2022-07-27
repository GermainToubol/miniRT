/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:50:42 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/13 20:41:06 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	skip_word(const char **str, const char *sep)
{
	while (**str && ft_strchr(sep, **str) == NULL)
	{
		if (**str == '\'')
		{
			(*str)++;
			while (**str && *((*str)++) != '\'')
				;
		}
		else if (**str == '\"')
		{
			(*str)++;
			while (**str && *((*str)++) != '\"')
				;
		}
		else
			(*str)++;
	}
}

static int	count_words_quoted(const char *str, const char *sep)
{
	int	count;

	count = 0;
	while (*str && ft_strchr(sep, *str) != NULL)
		str++;
	while (*str)
	{
		count++;
		skip_word(&str, sep);
		while (*str && ft_strchr(sep, *str) != NULL)
			str++;
	}
	return (count);
}

static char	*get_word_quoted(const char **str, const char *sep)
{
	const char	*str_start;
	char		*word;
	int			i;

	while (**str && ft_strchr(sep, **str) != NULL)
		(*str)++;
	str_start = *str;
	skip_word(str, sep);
	i = 0;
	while (str_start + i != *str)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str_start + i != *str)
	{
		word[i] = str_start[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split_quoted(const char *str, const char *sep)
{
	char	**strs;
	int		strs_size;
	int		i;

	strs_size = count_words_quoted(str, sep);
	strs = malloc(sizeof(char *) * (strs_size + 1));
	if (!strs)
		return (NULL);
	i = -1;
	while (++i < strs_size)
		strs[i] = NULL;
	i = 0;
	while (i < strs_size)
	{
		strs[i] = get_word_quoted(&str, sep);
		if (!strs[i])
			return (ft_free_tab(strs), NULL);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
