/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_eol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:30:44 by abelov            #+#    #+#             */
/*   Updated: 2024/05/24 19:21:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putstr_eol(const char *str, const char *eol)
{
	if (!str)
		return ;
	if (write(STDOUT_FILENO, str, ft_strlen(str)) == -1)
		return ;
	if (!eol || write(STDOUT_FILENO, eol, ft_strlen(eol)) == 1)
		return ;
}
