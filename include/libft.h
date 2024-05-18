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
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strstr_fixed(char *haystack, char *words[]);
char	*ft_strstr(char *str, char *to_find);
char	*ft_empty_string(size_t length);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_itoa(int nb);
char	*ft_itoa_buf(int nb, char *buf, size_t length);
char	*ft_uitoa_buf(unsigned int abs,  char *buf, size_t length);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
void	*ft_calloc(size_t nmemb, size_t size);

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
