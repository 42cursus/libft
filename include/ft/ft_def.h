/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:05:10 by abelov            #+#    #+#             */
/*   Updated: 2024/12/20 15:18:16 by sbelcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H
# ifndef EOF
#  define EOF -1
# endif

/**
 * When an expression contains operands of different built-in types,
 * and no explicit casts are present, the compiler uses built-in standard
 * conversions to convert one of the operands so that the types match.
 *
 * See also:
 *	 https://learn.microsoft.com =>
 *	 	=> /en-us/cpp/cpp/type-conversions-and-type-safety-modern-cpp
 */

# ifndef T_UINT

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

# endif //T_UINT

#endif //FT_DEF_H
