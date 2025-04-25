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

char	**alloc_memory(const char *(*stack)[2], int sp)
{
	int		i;
	char	**result;

	result = (char **)malloc((sp + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < sp)
	{
		result[i] = ft_strndup(stack[i][0], (stack[i][1] - stack[i][0]));
		if (result[i] == NULL)
		{
			while (i-- > 0)
				free(result[i]);
			return (free(result[i]), NULL);
		}
	}
	result[sp] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			sp;
	const char	*stack[MAX_STACK_SIZE][2];

	i = 0;
	if (!s)
		return ((char **)ft_calloc(1, sizeof(char *)));
	sp = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			stack[sp][0] = &s[i];
			stack[sp][1] = ft_strchrnul(&s[i], c);
			i += (int)(stack[sp][1] - stack[sp][0]);
			sp++;
		}
	}
	return (alloc_memory(stack, sp));
}
