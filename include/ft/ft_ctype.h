/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:01:19 by abelov            #+#    #+#             */
/*   Updated: 2024/05/21 03:01:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H
# include "ft_def.h"

typedef struct s_convert
{
	int				neg;
	int				any;
	unsigned long	acc;
	int				cutlim;
	unsigned long	cutoff;
}	t_conv;

int	ft_isspace(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isxdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isupper(int c);
int	ft_islower(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

#endif // FT_CTYPE_H
