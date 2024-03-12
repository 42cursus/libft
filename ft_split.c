/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:49:32 by abelov            #+#    #+#             */
/*   Updated: 2023/11/13 20:49:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static char	**ft_free_words(char **words, size_t i)
{
	while (i--)
	{
		if (&(words[i]) && *&(words[i]))
		{
			free(*&(words[i]));
			*&(words[i]) = NULL;
		}
	}
	free(*words);
	return (NULL);
}

static char	**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	words = (char **)ft_calloc((words_count + 1), sizeof(char *));
	if (!words)
		return (NULL);
	while (i < words_count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word = ft_get_word(s, c);
			if (!word)
				return (ft_free_words(words, i));
			words[i++] = word;
			s += (ft_strlen(word) + 1);
		}
	}
	words[i] = NULL;
	return (words);
}

/**
 * Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting 's' using the character 'c' as a delimiter.
 * The array must end with a NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s)
		return (NULL);
	line = ft_strdup((char *)s);
	if (!line)
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}
