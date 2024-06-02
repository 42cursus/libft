/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:04:01 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:23:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= '\x7f');
}

int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\t')
		|| (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r'));
}
