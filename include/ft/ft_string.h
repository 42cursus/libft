/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:55:53 by abelov            #+#    #+#             */
/*   Updated: 2024/05/21 02:55:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# include "ft_def.h"

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int chr);
char	*ft_strrchr(const char *s, int chr);
size_t	ft_strstr_fixed(char *haystack, char *words[]);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strnew(size_t length);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncat(char *dest, const char *src, unsigned int nb);
char	*ft_strnpcat(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strnew(size_t length);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_tab_str_join(char const **strs, size_t nmemb, const char *sep);
char	*ft_strdup(const char *const src);
void	*ft_calloc(size_t nmemb, size_t size);
long	ft_strtol(const char *nptr, char **endptr, int base);
t_ulong	ft_strtoul(const char *nptr, char **endptr, int base);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);
size_t	ft_strspn(const char *s, const char *accept);
size_t	ft_strcspn(const char *s, const char *reject);
size_t	ft_strcspn_reject(const char *s, const char *reject);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strpcat(char *dest, const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);
size_t	ft_strcspn(const char *s, const char *reject);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif //FT_STRING_H
