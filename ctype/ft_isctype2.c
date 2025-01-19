/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isctype2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:57:28 by abelov            #+#    #+#             */
/*   Updated: 2024/06/02 08:54:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_isprint(int c)
{
	return ((c >= '\x20') && (c < '\x7f'));
}

int	ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

int	ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}

/**
 * The ft_toupper() function converts lowercase letters to uppercase.
 * Returns its uppercase equivalent, if an uppercase representation exists
 * in the current locale.  Otherwise, it returns c.
 */
int	ft_toupper(int c)
{
	if (!((c >= 'a') && (c <= 'z')))
		return (c);
	return (c - 'a' + 'A');
}

/**
 * The ft_tolower() function converts uppercase letters to lowercase.
 * Returns its lowercase equivalent, if a lowercase representation exists
 * in the current locale.  Otherwise, returns c.
 */
int	ft_tolower(int c)
{
	if (!((c >= 'A') && (c <= 'Z')))
		return (c);
	return (c - 'A' + 'a');
}
