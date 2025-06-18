/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:31:19 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 15:54:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline __attribute__((always_inline))
size_t	ft_strlen_loc(const char *str)
{
	const char *const	ostr = str;

	while (*str)
		str++;
	return (str - ostr);
}

void	ft_putstr(const char *str)
{
	if (!str || write(STDOUT_FILENO, str, ft_strlen_loc(str)) == -1)
		return ;
}
