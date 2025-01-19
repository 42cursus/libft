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

static inline unsigned int	ft_strlen(const char *str)
{
	const char *const	ostr = str;

	while (*str)
		str++;
	return (str - ostr);
}

void	ft_putstr(const char *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
}
