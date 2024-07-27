/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_str_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:37:35 by abelov            #+#    #+#             */
/*   Updated: 2024/07/02 19:57:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_tab_str_free(char **str_tab)
{
	int	i;

	if (str_tab != NULL)
	{
		i = -1;
		while (str_tab[++i] != NULL)
			free(str_tab[i]);
		free(str_tab);
	}
}
