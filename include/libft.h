/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:44:05 by abelov            #+#    #+#             */
/*   Updated: 2023/11/02 17:44:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "gnl.h"
# include "ft_def.h"
# include "ft_ctype.h"
# include "ft_list.h"
# include "ft_tab.h"
# include "ft_string.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int nb);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_buf(int nb, char *buf, size_t length);
char	*ft_uitoa_buf(unsigned int abs,  char *buf, size_t length);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);

typedef size_t	(*t_ft_print_dispatch_f)(va_list *ap);

size_t	ft_print_p(va_list *argp);
size_t	ft_print_d(va_list *argp);
size_t	ft_print_s(va_list *argp);
size_t	ft_print_x(va_list *argp);
size_t	ft_print_upperx(va_list *argp);
size_t	ft_print_u(va_list *argp);
size_t	ft_print_c(va_list *argp);
size_t	ft_print_percent(va_list *argp);

char	*ft_uitoa(unsigned int nb);
char	*ft_uitoa_base(unsigned int nb, const char *base);
char	*ft_ultoa_buf_base(unsigned long abs,
						   char *buf, size_t length, const char *base);
char	*ft_print_pointer(unsigned long long nb);

#endif //LIBFT_H
