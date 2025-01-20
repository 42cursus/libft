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
# include "ft/gnl.h"
# include "ft/ft_def.h"
# include "ft/ft_ctype.h"
# include "ft/ft_list.h"
# include "ft/ft_stdlib.h"
# include "ft/ft_string.h"
# include "ft/ft_sys.h"
# include "ft/ft_tab.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *const s, int fd);
void	ft_putendl_fd(const char *const s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_eol(const char *str, const char *eol);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

/* ---------- PRINTF -------------------- */
# define FT_TERMINATOR 1
# define FT_ERROR -1
# define STRPTRNULL "(null)"
# ifdef __linux__
#  define PTRNULL "(nil)"
# endif

# ifndef PTRNULL
#  ifdef __APPLE__
#   define PTRNULL "0x0"
#  endif
# endif

typedef size_t	(*t_printf_f)(int fd, va_list *ap);
typedef size_t	(*t_snprintf_f)(char **buf, size_t size, va_list *ap);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vprintf(const char *fmt, va_list ap);
int		ft_vdprintf(int fd, const char	*fmt, va_list ap);
int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);

size_t	ft_print_p(int fd, va_list *ap);
size_t	ft_print_d(int fd, va_list *ap);
size_t	ft_print_s(int fd, va_list *ap);
size_t	ft_print_x(int fd, va_list *ap);
size_t	ft_print_upperx(int fd, va_list *ap);
size_t	ft_print_u(int fd, va_list *ap);
size_t	ft_print_c(int fd, va_list *ap);
size_t	ft_print_percent(int fd, va_list *ap);

size_t	ft_snprint_d(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_s(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_upperx(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_x(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_p(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_u(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_percent(char **buf, size_t size, va_list *ap);
size_t	ft_snprint_c(char **buf, size_t size, va_list *ap);

char	*ft_uitoa(unsigned int nb);
char	*ft_uitoa_base(unsigned int nb, const char *base);
char	*ft_ultoa_buf_base(unsigned long abs,
			char *buf, size_t length, const char *base);
char	*ft_print_pointer(unsigned long long nb);
void	*ft_reallocarray(void *ptr, size_t oldnmemb, size_t newnmemb,
			size_t size);
#endif //LIBFT_H
