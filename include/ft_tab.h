/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:03:53 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:03:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAB_H
# define FT_TAB_H

# include "ft_def.h"

void	ft_tab_foreach(int *tab, int length, void (*f)(int));
int		*ft_tab_map(int *tab, int length, int (*f)(int));
int		ft_tab_any(void const **tab, int (*f)(void *));
int		ft_tab_count_if(void **tab, int length, int (*f)(void *));
int		ft_tab_is_sort(int *tab, int length, int (*f)(int, int));
char	*ft_tab_string_join(char const **str_tab);
t_uint	ft_get_tab_size(void const **tab);
int		*ft_sort_int_tab(int *tab, int size);
void	ft_sort_string_tab(char **tab);
int		ft_string_tab_is_sort(char **tab, int (*f)(char *, char *));
void	ft_sort_string_tab_fun(char **tab, int (*cmp)(char *, char *));
int		*ft_init_int_tab(int len);
int		*ft_copy_int_tab(int *src, int *dst, int start, int end);

#endif //FT_TAB_H
